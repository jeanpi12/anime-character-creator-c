# anime-character-creator-c

An interactive command-line character creator written in C, where users build
characters across three anime universes: **Jujutsu Kaisen**, **Demon Slayer**,
and **Hunter x Hunter**. Each world has its own mechanics — sorcerers with
grades and cursed energy, demon slayers with breathing styles and slayer marks,
hunters with Nen types and stats — modeled with dedicated structs and enums.

I built this as a personal project to learn C through something I actually
wanted to make. What started as a small experiment grew into a study of how
real C programs are structured: separate source and header files per module,
a dispatcher routing user choices to specialized world handlers, `static`
helpers keeping module internals private, and `const`-correct pointer
parameters for safe data passing.

## How It Works

Run the program, pick a world from the menu, and walk through that world's
character creation flow. Each prompt fills in part of a struct representing
your character — name, class/rank, abilities, stats. When you're done, the
program prints a full character sheet. The session loops until you choose
to quit, so you can create as many characters as you want, switching between
worlds freely.

## Project Structure
main.c              # Entry point — calls into the dispatcher
decision.c / .h     # World-selection dispatcher with session loop
jujutsu_kaisen.c / .h    # JJK sorcerers (grade, affiliation, cursed energy)
demon_slayer.c / .h      # Demon slayers (breathing style, mark, stats)
hxh.c / .h          # Hunters (Nen type, physical/agility/intelligence stats)

`main.c` is intentionally tiny — it calls `decision()` and returns. The
dispatcher in `decision.c` owns the world-selection menu and the `do/while`
loop that keeps the session going. Each world module is self-contained:
it exposes one public entry function in its header, and keeps all its
helpers, structs, and enums private.

## Build and Run

**Windows (MSVC):**

cl main.c decision.c jujutsu_kaisen.c demon_slayer.c hxh.c
./main.exe

**Linux/macOS (GCC or Clang):**

gcc -Wall -Wextra -Wpedantic main.c decision.c jujutsu_kaisen.c demon_slayer.c hxh.c -o character_creator
./character_creator

No external dependencies — just a C compiler and the standard library.

## What I Learned

This project was where a lot of C concepts moved from "I've read about it"
to "I've used it in code I wrote." Specifically:

- **Multi-file compilation.** Splitting code across `.c` source files and
  `.h` header files, with include guards and proper separation of
  declarations (in headers) and definitions (in sources).
- **Structs and enums.** Modeling each world's domain — a sorcerer is a
  thing with a name, a grade, a cursed energy value; a grade is one of five
  named values rather than a magic integer.
- **Pointer parameters.** Passing structs by pointer for both modification
  (helpers that fill in stat fields) and read-only access (`const struct *`
  for print functions). Including the array-decay gotcha — the hard way.
- **The `static` keyword.** Keeping helper functions file-private so each
  module exposes only its one public entry function through its header.
- **Switch dispatch on enums.** Translating enum values to human-readable
  strings in the print functions, and routing the user's world choice to
  the right module in the dispatcher.
- **Defensive input handling.** Reading lines with `fgets`, stripping the
  trailing newline with `strcspn`, converting to numbers with `atoi` —
  consistent line-based input throughout.
- **The do/while loop pattern.** Running an interactive session that
  always executes at least once and continues based on user choice.
- **Reading compiler errors and warnings.** Most of the time on this
  project was spent learning to debug with `gcc`/`cl` output as the
  primary feedback channel, rather than guessing.

## Future Improvements

A few things I'd like to add or clean up:

- **Consistent input style across all modules.** Most input still uses
  `scanf` + `getchar`; migrating everything to `fgets` + `atoi` would
  be cleaner and avoid stdin-state bugs across loop iterations.
- **Shared I/O helpers.** The three world files have similar functions
  for reading numeric stats — these could be extracted into a shared
  `io.c` module to eliminate duplication.
- **Persistent character storage.** Currently each character is created,
  displayed, and forgotten. Saving them to a file would let users build
  up a roster across sessions.
- **A battle simulator.** Now that I have characters with stats, the
  natural next step is letting two of them fight, with mechanics
  appropriate to whichever world they come from.

## Notes

This is a learning project, not production software. The architecture
choices were made to practice specific C concepts — some of them are
deliberately verbose (e.g., explicit switch statements where a lookup
table would be more elegant) because explicit was easier to learn from.
I'm working on the cleanup list above as I keep learning the language.