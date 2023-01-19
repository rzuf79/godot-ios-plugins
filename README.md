# Piotr's iOS plugins for Godot

[Original repo](https://github.com/godotengine/godot-ios-plugins)

This fork contains iOS plugins that I use for my projects and will keep them up to date as long as I need them.
Currently supported custom plugins:

## Facebook
Taken from the amazing [DrMoriarty's repo](https://github.com/DrMoriarty/godot-facebook) and updated to FacebookSDK v13.1.0 and godot 3.5

## ATT
[DrMoriarty's repo](https://github.com/DrMoriarty/godot-ios-att) <br/>
Updated to work with Godot 3.5

## Firebase Analytics
[DrMoriarty's repo](https://github.com/DrMoriarty/godot-firebase-analytics) <br/>
Updated to work with Godot 3.5

## Rateme
Plugin for displaying native rating popus on iOS and Android <br/>
[DrMoriarty's repo](https://github.com/DrMoriarty/godot-rateme) <br/>
Updated to work with Godot 3.5

<br/><br/><br/><br/><br/>

# ORIGINAL README BELOW:

**Note:** iOS plugins are only effective on iOS (either on a physical device or
in the Xcode simulator). Their singletons will *not* be available when running
the project from the editor, so you need to export your project to test your changes.

## Instructions

- Clone this repository and its submodules:

```bash
git clone --recursive https://github.com/godotengine/godot-ios-plugins.git
```

You might have to the update `godot` submodule in case you require latest (unreleased) Godot changes. To do this, run:

```bash
cd godot
git fetch
git checkout origin/<branch you want to use>
```

- Alternatively, you can use pre-extracted Godot headers that will be provided
  with release tag on the [Releases page](https://github.com/godotengine/godot-ios-plugins/releases).
  To do this, clone this repository without submodules:

```bash
git clone https://github.com/godotengine/godot-ios-plugins.git
```

Then place the extracted Godot headers in the `godot/` directory.
If you choose this option, you can skip next the step which generates Godot headers.

- To generate Godot headers, you need to run the compilation command inside the `godot` submodule directory:

### For Godot 3.x:

```bash
scons platform=iphone target=debug
```

### For Godot 4.x:

```bash
scons platform=ios target=debug
```

You don't have to wait for full engine compilation, as header files are generated first.
Once the actual compilation starts, you can stop this command by pressing <kbd>Ctrl + C</kbd>.

- Run the command below to generate an `.a` static library for chosen target:

```bash
scons target=<debug|release|release_debug> arch=<arch> simulator=<no|yes> plugin=<plugin_name> version=<3.x|4.0>
```

**Note:** Godot's official `debug` export templates are compiled with the `release_debug` target, *not* the `debug` target.

## Building a `.a` library

- Run `./scripts/generate_static_library.sh <plugin_name> <debug|release|release_debug> <godot_version>`
  to generate `fat` static library with specific configuration.
- The result `.a` binary will be stored in the `bin/` folder.

## Building a `.xcframework` library

- Run `./scripts/generate_xcframework.sh <plugin_name> <debug|release|release_debug> <godot_version>`
  to generate `xcframework` with specific configuration.
  `xcframework` allows plugin to support both `arm64` device and `arm64` simulator.
- The result `.xcframework` will be stored in the `bin/` folder as well as intermidiate `.a` binaries.

## Documentation

Each plugin provides a `README.md` file which contains documentation and examples.
