# Prisma
<p align="center">
  <img alt="prisma logo .svg" width="25%" src="assets/logos/prisma-shatteredHierarchy-nogaps.svg" />
</p>

## About
Prisma is a video game engine waiting to be born.
This project was started around the 28th of March 2025, and is hoping to one day be able to produce games.

>[!NOTE]
> Prisma is just getting started.
> If you have any feedback or suggestions to give, feel free to [submit an issue](https://github.com/jas31415/prisma/issues/new) about it.

## Plans
Since this entire project is still a ball of uncertainty, this file will be used to list plans related to the engine.

Right now, the goal is to experiment with with different C/C++ libraries in corresponding branches.
In the end, the library candidate that works the best for Prisma will merge with main.
The other branches will be discontinued or archived, but never deleted.

- [ ] **[SDL3](https://www.libsdl.org/):** $\color{gray}\texttt{branch}$
- [ ] **[SFML](https://www.sfml-dev.org/):** $\color{gray}\texttt{branch}$
- [ ] **[raylib](https://www.raylib.com/):** [branch](https://github.com/jas31415/prisma/tree/libcandidate-raylib)
- [ ] **MoreIdeasHere:** If you got any suggestions, [submit an issue](https://github.com/jas31415/prisma/issues/new) with any combination of libraries that you think Prisma should try out.

Wherever this goes, Prisma should be loud and proud about its associations to queer spaces.

## For Developers
Here are the instructions for building and compiling this project.
Prisma currently uses the g++ compiler along with Make.
Use default configuration, "main" as build target, and "main" as launch target.
>[!IMPORTANT]
> Experimental branches now use CMake with Ninja, so to work in those you will need to have these installed and CMake's correspondent plugin or tool.
> Once a library candidate has been chosen, it will merge with the main branch and Makefiles will thenceforth not be used.
> If these instructions are unclear or contain an error, please [submit an issue](https://github.com/jas31415/prisma/issues/new) detailing the mistake and other possibly relevant information.

## License
Prisma is licensed under the MIT License:

- You are free to use Prisma for any purpose.
- You may freely study Prisma's code and modify it for personal use.
- You may use Prisma's code in your own product and even distribute it under a different license, but you must clearly document that you've derived from the MIT-licensed Prisma.

The above explanation reflects my understanding of my own license terms and does not constitute legal advice.
