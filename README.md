## Mandelbrot Set

The Mandelbrot set is a famous fractal that is defined iteratively using the formula \( z_{n+1} = z_n^2 + c \), where \( z \) starts at \( 0 \) and \( c \) is a complex number. The set consists of all complex \( c \) for which the sequence remains bounded.

![Alt text](https://github.com/wmBolles/42-Fract-Ol/blob/master/images/mandelbrot.png)


## Julia Set

Julia sets are fractals similar to the Mandelbrot set but are defined by iterating the function \( z_{n+1} = z_n^2 + c \) starting from a constant \( c \), while \( z \) varies across the complex plane.

![Alt text](https://github.com/wmBolles/42-Fract-Ol/blob/master/images/julia.png)

## Features

- **Mandelbrot Set Rendering:** Generates high-resolution images of the Mandelbrot set by iterating over points in the complex plane and determining convergence.
  
- **Julia Set Rendering:** Allows visualization of Julia sets based on a constant \( c \) chosen by the user.
