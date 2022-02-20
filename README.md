# RouLette Vsh Menu
Vsh Menu that loads Playstation 3 game menus like Lexicon, Serendipity, Paradox and FrenchModdingTeam. 

To open the vsh menu press R3 + L1

## Features
- Load sprx menus into game without eboots (.sprx)
- Load InGame payloads (.bin)
- Write to into game memory on boot or constant

Preview:
![2022-02-19_23-13-22](https://user-images.githubusercontent.com/9206290/154830967-b154e1f3-ba8d-42b9-b5db-ac16975186e1.png)
![2022-02-19_23-55-07](https://user-images.githubusercontent.com/9206290/154832074-0e72906e-e717-4c78-b5b7-9e81271b5cb9.png)
![2022-02-19_23-58-49](https://user-images.githubusercontent.com/9206290/154832079-eeb3c28a-f648-4c90-bafd-5fa49c64f15e.png)


## Notes
- Some games have exceeded their memory limit so using the function GamePatching::StartSprx will not work. So a workaround is to make a eboot for that game to load your sprx. (This is mainly for AAA games like GTAV and RDR)
- Cobra 8.2 or above is required to use enstone menus. If you are on 4.84 Rebug DEX and want to use Cobra 8.3 download [4.84 DEX stage2.bin](https://github.com/Evilnat/Cobra-PS3/blob/master/8.3/4.84/NORMAL/DEX/BIN/stage2.bin "4.84 DEX stage2.bin") transfer the file to /dev_rebug/rebug/cobra/ to your PS3 and then change the .bin to .dex

## Prerequisites
- Visual Studio 2013+
- Sony PS3 4.75+ SDK w/ Visual Studio Integration
- [Fixed std::string library](https://github.com/skiff/libpsutil/releases "Fixed std::string library")
 
## Installation
1. In your PS3 file system go to /dev_hdd0/plugins/ and create a new folder named RouLetteVshMenu

![plugins](https://github.com/TheRouletteBoi/RouLetteVshMenu/blob/main/Resources/plugins.PNG)

2. Transfer RouLetteVshMenu.sprx into /dev_hdd0/plugins/RouLetteVshMenu/

![sprx](https://github.com/TheRouletteBoi/RouLetteVshMenu/blob/main/Resources/sprx.PNG)

3. Navigate back to /dev_hdd0 and you will find a file named boot_plugins.txt (If file is not found just create one named boot_plugins.txt)

![hdd0](https://github.com/TheRouletteBoi/RouLetteVshMenu/blob/main/Resources/hdd0.PNG)

5. Open boot_plugins.txt and make a new line and type /dev_hdd0/plugins/RouLetteVshMenu/RouLetteVshMenu.sprx

![bootplugins](https://github.com/TheRouletteBoi/RouLetteVshMenu/blob/main/Resources/bootplugins.PNG)

5. Restart your console

## Credits
@Jordy-Nateur for his paf classes Module, PhHandler, PhPlane, PhText, PhWidget and View and his VSH-Playground
