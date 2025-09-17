do {
    # Get all .cpp files in the current directory
    $cppFiles = Get-ChildItem -Filter *.cpp
    if ($cppFiles.Count -eq 0) {
        Write-Host "No C++ files found in the current directory."
        break
    }

    # Display the list of files
    Write-Host "`nAvailable C++ programs:"
    for ($i = 0; $i -lt $cppFiles.Count; $i++) {
        Write-Host "$($i + 1). $($cppFiles[$i].Name)"
    }
    Write-Host "0. Exit"

    # Prompt user for selection
    $choice = Read-Host "`nEnter the number of the program you want to run"

    # Exit condition
    if ($choice -eq '0') {
        break
    }

    # Validate input
    if (-not ($choice -as [int]) -or $choice -lt 1 -or $choice -gt $cppFiles.Count) {
        Write-Host "Invalid choice."
        continue
    }

    $selectedFile = $cppFiles[$choice - 1].FullName
    $directory = [System.IO.Path]::GetDirectoryName($selectedFile)
    $baseName = [System.IO.Path]::GetFileNameWithoutExtension($selectedFile)
    $exeName = Join-Path $directory "$baseName.exe"
    $logFile = Join-Path $directory "cpp_run_log.txt"

    # Compile using g++ and measure compile time
    Write-Host "`nCompiling $($cppFiles[$choice - 1].Name)..."
    $compileStart = Get-Date
    g++ "$selectedFile" -o "$exeName"
    $compileEnd = Get-Date
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Compilation failed."
        continue
    }

    $compileDuration = $compileEnd - $compileStart
    $exeSizeBytes = (Get-Item "$exeName").Length
    $exeSizeKB = [math]::Round($exeSizeBytes / 1KB, 2)

    # Run the executable and measure execution time
    Write-Host "`n==============================="
    Write-Host " Running: $($cppFiles[$choice - 1].Name) "
    Write-Host "===============================`n"

    $execStart = Get-Date
    & "$exeName"
    $execEnd = Get-Date

    $execDuration = $execEnd - $execStart

    Write-Host "`n==============================="
    Write-Host " Program finished executing. "
    Write-Host "==============================="
    Write-Host "Executable Size: $exeSizeKB KB"
    Write-Host "Compile Time: $($compileDuration.TotalSeconds) seconds"
    Write-Host "Execution Time: $($execDuration.TotalSeconds) seconds"

    # Log the results
    $logEntry = @"
[$(Get-Date -Format "yyyy-MM-dd HH:mm:ss")]
Program: $($cppFiles[$choice - 1].Name)
Executable Size: $exeSizeKB KB
Compile Time: $($compileDuration.TotalSeconds) seconds
Execution Time: $($execDuration.TotalSeconds) seconds
---------------------------------------------
"@
    Add-Content -Path $logFile -Value $logEntry

    # Clean up executable
    Remove-Item "$exeName" -Force

    Write-Host "`nYou can run another program or exit."
} while ($true)

Write-Host "`nSession ended. Goodbye!"
