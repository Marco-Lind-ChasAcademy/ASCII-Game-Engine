# 🕹️ ASCII-Game-Engine  
*A tiny 2D ASCII game engine in pure C — for those who like their pixels made of text.*

## What's this?

**ASCII-Game-Engine** is my side project, written entirely in C, that brings 2D game dev into the world of text-mode. It’s sprite-based, fast, and practical — built for when inspiration strikes and I just want to make something *move*.

Whether you’re animating little '@' dudes, building dungeons out of `#`, or just love the aesthetics of the terminal, this engine gives you the low-level tools to make it happen.

## Features

- 🧱 Sprite-based rendering with ASCII characters  
- 🏎️ Performance-focused — minimal overhead, no bloat  
- 🎮 Input handling for real-time games  
- ⌨️ Clean C API — no weird macros or hidden magic  
- 💡 Easy to plug into your own projects  

## Why?

Because sometimes pixel art is too high-res.  
Because writing in pure C is fun.  
Because making games in the terminal just feels good.

## Status
This is a personal, inspiration-driven project.
Sometimes I’ll hack on it for hours. Sometimes it naps for weeks.
It’s not a full-blown engine (yet?), but it’s fast, lean, and ready to play.

## License
Released under the GNU General Public License v2.0.
You can use it, share it, and change it — just keep it open.
See the LICENSE file if you enjoy reading legalese.

## Note:
The engine (yep, that’s game.exe) is meant to be run in fullscreen with a font size of 33 — otherwise things might look a bit... weird.

I’ve included a pre-built game.exe so even folks without a C compiler can jump in and give it a spin.
Fair warning: since it’s unsigned, your antivirus might throw a tantrum.
If you’d rather not deal with that, just compile it yourself — no drama, no red flags.

## Build

```bash
gcc -o game src/*.c
./game