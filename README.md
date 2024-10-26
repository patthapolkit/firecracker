# Getting Started with Firecracker

## Running Firecracker

### Getting a rootfs and Guest Kernel Image

To successfully start a microVM, you will need an uncompressed Linux kernel
binary, and an ext4 file system image (to use as rootfs).

```bash
ARCH="$(uname -m)"

latest=$(wget "http://spec.ccfc.min.s3.amazonaws.com/?prefix=firecracker-ci/v1.10/x86_64/vmlinux-5.10&list-type=2" -O - 2>/dev/null | grep "(?<=<Key>)(firecracker-ci/v1.10/x86_64/vmlinux-5\.10\.[0-9]{3})(?=</Key>)" -o -P)

# Download a linux kernel binary
wget "https://s3.amazonaws.com/spec.ccfc.min/${latest}"

# Download a rootfs
wget "https://s3.amazonaws.com/spec.ccfc.min/firecracker-ci/v1.10/${ARCH}/ubuntu-22.04.ext4"

# Download the ssh key for the rootfs
wget "https://s3.amazonaws.com/spec.ccfc.min/firecracker-ci/v1.10/${ARCH}/ubuntu-22.04.id_rsa"

# Set user read permission on the ssh key
chmod 400 ./ubuntu-22.04.id_rsa
```

### Getting a Firecracker Binary

To download the latest firecracker release, run:

```bash
ARCH="$(uname -m)"
release_url="https://github.com/firecracker-microvm/firecracker/releases"
latest=$(basename $(curl -fsSLI -o /dev/null -w  %{url_effective} ${release_url}/latest))
curl -L ${release_url}/download/${latest}/firecracker-${latest}-${ARCH}.tgz \
| tar -xz

# Rename the binary to "firecracker"
mv release-${latest}-$(uname -m)/firecracker-${latest}-${ARCH} firecracker
```

### Starting firecracker

0. Firecracker requires the KVM Linux kernel module to perform its virtualization and emulation tasks. Ensure that the KVM module is loaded.
1. Run script `./start_firecracker.sh` to start firecracker
2. Open another terminal and run script `./start_microvm.sh` to create a vm and ssh into it
3. scp `fibo.c`, `fibo.py`, `run_fibo.sh`, `run_fibo_c.sh` to the vm
4. Run `./run_fibo.sh` to run the python script, the result will be stored in `result.txt`
5. Run `./run_fibo_c.sh` to run the c script, the result will be stored in `result.txt`
