# RouLette Vsh Menu
Vsh Menu that loads Playstation 3 game menus like Lexicon, Serendipity, Paradox and FrenchModdingTeam. 

To open the vsh menu press R3 + L1

## Table of contents

 * [Features](#features)
 * [Preview](#preview)
 * [Notes](#notes)
 * [Download](#download)
 * [Installation](#installation)
 * [How to build](#how-to-build)
    * [Visual Studio 2013+](#visual-studio-2013)
    * [Sony PS3 4.75+ SDK with Visual Studio Integration](#sony-ps3-475-sdk-with-visual-studio-integration)
    * [Fixed std::string library](#fixed-stdstring-library)
    * [Git](#git)
    * [Cloning](#cloning)
 * [Staying Up To Date](#staying-up-to-date)
 * [Discontinued Features](#discontinued-features)
 * [Credits](#credits)

## Features
- Load sprx menus into game without eboots (.sprx)
- Load [InGame payloads](https://github.com/TheRouletteBoi/ingame_payloads) (.bin)
- Write to into game memory on game startup or constantly


## Preview
![2022-04-04_01-17-50](https://user-images.githubusercontent.com/9206290/161502591-f2ec4acb-6646-4d5d-a181-6ab92cc5844f.png)
![2022-04-04_01-18-04](https://user-images.githubusercontent.com/9206290/161502608-371a0f22-82f3-41d2-9795-b21c0fdfb14b.png)
![2022-04-04_01-18-18](https://user-images.githubusercontent.com/9206290/161502622-749c4b1a-bde3-4c83-b78a-62ed5bcc1643.png)


## Notes
- Some games have exceeded their memory limit so using the function GamePatching::StartSprx will not work. So a workaround is to make a eboot for that game to load your sprx. (This is mainly for AAA games like GTAV and RDR)
- Cobra 8.3 or above is required to use the launcher. If you are on 4.84 Rebug DEX and want to use Cobra 8.3 download [4.84 DEX stage2.dex](https://github.com/Evilnat/Cobra-PS3/blob/master/8.3/4.84/REBUG/REX/BIN/stage2.dex "4.84 DEX stage2.dex") and [stage2.cex](https://github.com/Evilnat/Cobra-PS3/blob/master/8.3/4.84/REBUG/REX/BIN/stage2.cex "stage2.cex") transfer the file to /dev_rebug/rebug/cobra/ to your PS3
- CCAPI 2.80rev5 or lower is required to use enstone menus. Also a console restart is required if you want to exit the game. To load a enstone menu open RouLetteVshMenu click on the menu you want to load then mount your game of choice and press R2 + L3 + R3 then finally start the game.
- If you get placed into Safe Mode when loading into a game try to unload WebMan before starting any game (R2 + L3 + R3).

## Download 
[Releases](https://github.com/TheRouletteBoi/RouLetteVshMenu/releases)
 
 
## Installation
1. In your PS3 file system go to /dev_hdd0/plugins/ and transfer folder named RouLetteVshMenu provided in [Releases](https://github.com/TheRouletteBoi/RouLetteVshMenu/releases) and the inside of RouLetteVshMenu folder should look like this

![plugins](https://github.com/TheRouletteBoi/RouLetteVshMenu/blob/main/Resources/plugins.PNG)
![sprx](https://github.com/TheRouletteBoi/RouLetteVshMenu/blob/main/Resources/sprx.PNG)

2. Navigate back to /dev_hdd0 and you will find a file named boot_plugins.txt (If file is not found just create one named boot_plugins.txt)

![hdd0](https://github.com/TheRouletteBoi/RouLetteVshMenu/blob/main/Resources/hdd0.PNG)

3. Open boot_plugins.txt and make a new line and type /dev_hdd0/plugins/RouLetteVshMenu/RouLetteVshMenu.sprx

![bootplugins](https://github.com/TheRouletteBoi/RouLetteVshMenu/blob/main/Resources/bootplugins.PNG)

4. Restart your console


## How to build

Requirements:

 * [Visual Studio 2013+](#visual-studio-2013)
 * [Sony PS3 4.75+ SDK with Visual Studio Integration](#sony-ps3-475-sdk-with-visual-studio-integration)
 * [Fixed std::string library](#fixed-stdstring-library)
 * [Git](#git)
 * [Cloning](#cloning)
 
 If you have the above requirements you can skip to [cloning the git repo](#cloning-repository).
 
 
### Visual Studio 2013+
Visual Studio 2013 isn't required to build but is required to setup [Visual Studio Integration](#sony-ps3-475-sdk-with-visual-studio-integration). With that being said if you don't plan on creating projects you can use any version of Visual Studio.

[Download Link](https://archive.org/details/en_visual_studio_ultimate_2013_x86_dvd_3175319)

### Sony PS3 4.75+ SDK with Visual Studio Integration
[Visual Studio Integration](https://archive.org/details/pro-dgfor-play-station-3v-470.1.0-leaked-by-01cedric-and-sn-0w-fr-1tz) is **REQUIRED** in order to build the project using Visual Studio.

[Download Link](https://archive.org/details/ps3-4.75-sdk)

### Fixed std::string library
Follow their [install tutorial](https://github.com/skiff/libpsutil#installation)

[Download Link](https://github.com/skiff/libpsutil/releases)

### Git

If you haven't installed git on your system go and do so it is **REQUIRED** for setting up a working build environment.

[Download Link](https://git-scm.com/download/win)

### Cloning

Clone the repository including submodules:
```bash
git clone https://github.com/TheRouletteBoi/RouLetteVshMenu.git --recursive || echo "You don't have git installed, install it from https://git-scm.com/download/win"
```

Now, you will be able to open the solution, and simply build it in Visual Studio.

## Staying Up To Date

Pull the latest changes from Github:
```bash
git pull && git submodule update
```


## Discontinued Features
* [C++ boost library](https://github.com/TheRouletteBoi/RouLetteVshMenu/tree/4524ebb946bc536b7b1d84a07c4b5489cc2e1faa) For rich features like boost::function, boost::unordered_map and much more.
* [simpleini config](https://github.com/TheRouletteBoi/RouLetteVshMenu/tree/bd7f9dc7cd4b64833795e4f148eb294852db446a) For reading/editing .ini files



## Credits
[@Jordy-Nateur](https://github.com/Jordy-Nateur) for his paf classes Module, PhHandler, PhPlane, PhText, PhWidget and View and his VSH-Playground

[@CaneHaxs](https://github.com/CaneHaxs) for some of the Paradox patches, terrorizer patch and many others
