import os

print("[+] Compilation...")
os.system("make clean")
os.system("make")

print("[+] Lancement de QEMU...")
os.system("qemu-system-x86_64 -drive format=raw,file=Katux.img")

