# Basic3D - Simple Wireframe Rendering of .obj Files

![Torus Example](https://github.com/agiraudet/basic3d/blob/master/examples/torus.png)

Basic3D is a minimalist wireframe rendering tool designed to display .obj files without any optimizations. Currently, the program supports rendering vertices and edges only.

## Installation

Before running Basic3D, you need to compile the project. Follow the steps below for installation:

1. Clone the repository:

```
git clone https://github.com/agiraudet/basic3d.git
```

2. Navigate to the project directory:

```
cd basic3d
```

3. Compile the project using `make`:

```
make
```

## Usage

To use Basic3D, simply run the executable with the following command:

```
./basic3d <file.obj>
```

If you don't specify a file, the program will automatically generate a cube for visualization.

## Prerequisites

Basic3D requires the SDL2 library to function properly. To install SDL2 on Debian-based distributions like Ubuntu, you can use the following command:

```
sudo apt install libsdl2-dev
```

For Fedora-based systems, use the following command:

```
sudo dnf install SDL2-devel
```

For other platforms, please refer to the respective package manager or download SDL2 from its official website.

## Example

Below is an illustration of a rendered torus using Basic3D:

![Torus Example](https://github.com/agiraudet/basic3d/blob/master/examples/torus.png)

## Features

At its current state, Basic3D has the following features:

- Rendering .obj files in wireframe mode
- Displaying vertices and edges

## Future Enhancements

While Basic3D is designed to be a simple wireframe renderer, future versions may include the following enhancements:

- Shading and coloring support
- Basic lighting models
- Improved rendering performance through optimizations
- Support for additional 3D file formats

## License

Basic3D is licensed under the [MIT License](https://github.com/agiraudet/basic3d/blob/master/LICENSE). Feel free to use, modify, and distribute the code in accordance with the terms of the license.
