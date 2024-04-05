# Setting up vcpkg for C++ Project

To integrate vcpkg into your C++ project, follow these steps:

1. **Clone vcpkg Repository**:
   - Navigate to `C:/Program Files`.
   - Clone the vcpkg repository by running:
     ```
     git clone https://github.com/microsoft/vcpkg
     ```

2. **Bootstrap vcpkg**:
   - Navigate into the `vcpkg` directory.
   - Run the bootstrap script:
     ```
     .\bootstrap-vcpkg.bat
     ```

3. **Add vcpkg to PATH**:
   - Add the vcpkg directory to your system's PATH environment variable. This step ensures that you can run vcpkg from any directory.

4. **Integrate vcpkg with Visual Studio**:
   - Run the following command in the vcpkg directory:
     ```
     .\vcpkg integrate install
     ```
   - This command will apply user-wide integration for the vcpkg root. It will provide the CMake command that should be used in your CMake projects.

5. **Integrate vcpkg with Project**:
   - In your C++ project, open the NuGet Package Manager Console.
   - Paste the following command to install vcpkg as a NuGet package in your project:
     ```
     Install-Package "vcpkg.C.ProgramFiles.vcpkg" -Source "C:\Program Files\vcpkg"
     ```

6. **Install Packages**:
   - Finally, you can install any desired packages using vcpkg:
     ```
     .\vcpkg install [package]
     ```
   - Replace `[package]` with the name of the package you want to install.

By following these steps, you can integrate vcpkg into your C++ project and easily manage external dependencies.
