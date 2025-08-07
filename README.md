# 🕹️ ascii-engine  
*A tiny 2D ASCII game engine in pure C — for those who like their pixels made of text.*

## What's this?

**ascii-engine** is my side project, written entirely in C, that brings 2D game dev into the world of text-mode. It’s sprite-based, fast, and practical — built for when inspiration strikes and I just want to make something *move*.

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

## Build

```bash
gcc -o game main.c src/*.c
./game