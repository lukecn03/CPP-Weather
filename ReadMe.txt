for cpp-weather:

1. go to C:/Program Files
2. git clone https://github.com/microsoft/vcpkg
3. .\vcpkg\bootstrap-vcpkg.bat
3. Add vcpkg to PATH
4. .\vcpkg integrate install
5. .\vcpkg integrate project
6. Go to project->tools->NuGet package manager->Nuget console, and paste in: Install-Package "vcpkg.C.ProgramFiles.vcpkg" -Source "C:\Program Files\vcpkg"
7. .\vcpkg install [package]

Can then use [package in project]



(open .sin file in a folder for a project view in ms vc)
finish readme
git commits

problem at step 6 i think

look at other vcpkg install




"-DCMAKE_TOOLCHAIN_FILE=C:/Program Files/vcpkg/scripts/buildsystems/vcpkg.cmake"

Install-Package "vcpkg.C.ProgramFiles.vcpkg" -Source "C:\Program Files\vcpkg"