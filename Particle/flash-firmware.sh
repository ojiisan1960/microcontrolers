
sudo dfu-util -d 2b04:d006 -a 0 -s 0x8020000 -D system-part1-0.5.0-photon.bin
sudo dfu-util -d 2b04:d006 -a 0 -s 0x8060000:leave -D system-part2-0.5.0-photon.bin
