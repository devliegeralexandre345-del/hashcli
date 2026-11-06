# hashcli

A simple CLI tool for computing hash values of files or strings.

## Features

- Computes CRC32, FNV-1a, and MD5 hashes
- Reads from file or standard input
- Outputs results in hexadecimal format

## Building

```bash
cmake -B build
cd build
ninja
```

## Usage

```bash
./hashcli <filename>
```
