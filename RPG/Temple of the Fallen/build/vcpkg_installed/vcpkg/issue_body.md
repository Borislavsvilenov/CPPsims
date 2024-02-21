Package: openal-soft:arm64-osx@1.23.1

**Host Environment**

- Host: arm64-osx
- Compiler: AppleClang 15.0.0.15000100
-    vcpkg-tool version: 2024-02-07-8a83681f921b10d86ae626fd833c253f4f8c355b
    vcpkg-scripts version: 62f4702df 2024-02-21 (11 minutes ago)

**To Reproduce**

`vcpkg install `
**Failure logs**

```
-- Using cached kcat-openal-soft-1.23.1.tar.gz.
-- Cleaning sources at /Users/borislavsvilenov/vcpkg/buildtrees/openal-soft/src/1.23.1-180897dbaa.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source /Users/borislavsvilenov/vcpkg/downloads/kcat-openal-soft-1.23.1.tar.gz
-- Applying patch c12ada68951ea67a59bef7d4fcdf22334990c12a.patch
-- Using source at /Users/borislavsvilenov/vcpkg/buildtrees/openal-soft/src/1.23.1-180897dbaa.clean
-- Found external ninja('1.11.1').
-- Configuring arm64-osx
-- Building arm64-osx-dbg
-- Building arm64-osx-rel
-- Fixing pkgconfig file: /Users/borislavsvilenov/vcpkg/packages/openal-soft_arm64-osx/lib/pkgconfig/openal.pc
CMake Error at scripts/cmake/vcpkg_find_acquire_program.cmake:166 (message):
  Could not find pkg-config.  Please install it via your package manager:

      brew install pkg-config
Call Stack (most recent call first):
  scripts/cmake/vcpkg_fixup_pkgconfig.cmake:203 (vcpkg_find_acquire_program)
  /Users/borislavsvilenov/.cache/vcpkg/registries/git-trees/d23d6573247830bd439e418fe0e31321de778d85/portfile.cmake:101 (vcpkg_fixup_pkgconfig)
  scripts/ports.cmake:170 (include)



```
**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "dependencies": [
    "sfml"
  ]
}

```
</details>
