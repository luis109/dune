# Building with CMake presets

DUNE provides configure, build, and test presets in `CMakePresets.json`.
CMake 3.21 or newer is required. Run the commands below from the repository
root.

The available configurations are:

| Preset | Build directory | Purpose |
| --- | --- | --- |
| `dev` | `build/dev` | Release build used for day-to-day development |
| `debug` | `build/debug` | Debug build with debug symbols and `DUNE_DEBUG` enabled |
| `tests` | `build/tests` | Release build with the test programs enabled |
| `legacy` | `build/legacy` | Release build using the legacy C++14 code path |

List the available presets with:

~~~sh
cmake --list-presets
cmake --build --list-presets
ctest --list-presets
~~~

Configure a build directory and compile it by using presets with the same
name. For example, the normal development workflow is:

~~~sh
cmake --preset dev
cmake --build --preset dev --parallel 2
~~~

For a build suitable for source-level debugging, use:

~~~sh
cmake --preset debug
cmake --build --preset debug --parallel 2
~~~

Replace `2` with a suitable number of concurrent compiler processes for the
machine. The configure command must be run at least once before its build
preset can be used. Run it again after changing CMake options or presets.

### Starting with a fresh CMake cache

A normal configure preserves values already stored in the build directory's
`CMakeCache.txt`. To discard that configuration state and configure the preset
from a fresh cache, use:

~~~sh
cmake --fresh --preset dev
~~~

This is useful after removing or renaming cache variables, or when an old
cached value is producing unexpected behavior. Replace `dev` with the desired
preset name. The `--fresh` option requires CMake 3.24 or newer; it recreates
CMake's cache and generated configuration files but does not delete the entire
build directory.

## Testing

Tests have a separate configuration so that the normal development build does
not compile the test programs. Configure and build the `tests` preset before
running CTest:

~~~sh
cmake --preset tests
cmake --build --preset tests --parallel 2
ctest --preset tests --parallel 2
~~~

The test preset prints the output of any failed test. Standard CTest options
can be added after the preset, for example:

~~~sh
# List tests without running them.
ctest --preset tests -N

# Run tests whose names match a regular expression.
ctest --preset tests -R IMC

# Rerun tests that failed in the previous run.
ctest --preset tests --rerun-failed
~~~

## Packaging

The `package` build preset invokes CPack's package target using the configured
`dev` build:

~~~sh
cmake --preset dev
cmake --build --preset package --parallel 2
~~~

On Linux, the resulting `.tar.bz2` archive is written under `build/dev`.
