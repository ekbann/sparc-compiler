# How to Install and Use QEMU

#### Installing 7-Zip

By default, 7-Zip is available on Debian 11 Bullseye standard repository making the installation straightforward.

In your terminal, begin the installation using the following command.

```sudo apt install p7zip-full```

Type Y, then press the ENTER KEY to proceed.

#### QEMU and KVM:
QEMU can be combined with KVM to use hardware virtualization features of your CPU. QEMU + KVM will get you almost near native hardware performance.

Hardware virtualization feature is disabled by default on AMD and Intel CPU’s. So you will have to enable them manually if you do wish to use it.

I recommend you enable hardware virtualization. If you don’t do so, QEMU will be very slow.

#### Enabling Hardware Virtualization:
If you have Intel CPU, then all you have to do is, enable VT-x or VT-d from the BIOS of your motherboard.

For AMD CPU, you have to enable AMD-v from the BIOS of your motherboard.

If your CPU supports hardware virtualization, and you enabled it from the BIOS of your computer, then you can check whether Virtualization is enabled from your Debian 9 Stretch machine with the following command:

```$ lscpu | grep Virt```

As you can see, hardware virtualization is enabled.

#### Installing QEMU and KVM:
QEMU is not installed by default on Debian 9 Stretch. But it is available in the official package repository of Debian 9 Stretch. So you can easily install it.

First, update the APT package repository cache with the following command:

```$ sudo apt update```

The APT package repository cache should be updated.

Now install QEMU with the following command:

```$ sudo apt install qemu qemu-kvm qemu-system-sparc```

Now press y and then press <Enter> to continue.

KVM and QEMU should be installed.

#### Using QEMU and KVM:

In this section, I will show you how to install Alpine Linux on a QEMU + KVM virtual machine.

```
git clone https://github.com/ekbann/sparc-compiler
cd sparc-compiler/ss5
7z e SunOS-4.1.4.7z.001
qemu-img create -f qcow2 sunos414.img 2G
startx
qemu-system-sparc -vga cg3 -M SS-5 -bios ss5.bin -m 32 -hda sunos414.img -hdb Solaris1_1_2.iso
```

Creating a VM Directory:

First, create a directory where all your VM data will be stored. I will call this VM directory from now on.

Create a VM directory with the following command:

```$ mkdir -p ~/qemu/ss5```

Now navigate to the VM directory with the following command:

```$ cd ~/qemu/ss5```
