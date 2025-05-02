the point of persistence is to keep data **intact** even in case of a power loss, made possible by HDDs and SSDs. as a last step to [[virtualization]], we tacked virtualizing storage with 2 key abstractions: **file** and **directory**.

a **file** is a linear array of bytes. each file has a low-level name as the **inode number**. the [[filesystem]] is responsible for storing data persistently on disk.

a **directory** also has a low-level name (inode number). however, it contains list of pairs: `(user-readable name, inode number)`, i.e. `("foo", 10)` meaning a file "foo" has low-level name "10". each entry can refer to either files or directories.

## directory tree
literally just a tree of the filesystem, starting from the root directory `/`.

![[Pasted image 20250502163110.png]]

## file manipulation
### creation
uses the `open()` system call with the `O_CREAT` flag.
- `O_CREAT` creates the file
- `O_RDONLY`, `O_WRONLY` makes the file read/write only
- `O_TRUNC` zeros the file out (removes any existing content)

the `open()` syscall returns a **file descriptor**, which is an integer, used to access files
- `stdin`: fd = 0
- `stdout`: fd = 1
- `stderr`: fd = 2

### non-sequential read-write
an open file has a **current offset**, which determines where the next read/write will begin. 

to update the current offset:
- implicitly: when a read or write of $N$ bytes take place, $N$ is added to the current offset
- explicitly: use `lseek()` to pinpoint position.

```c
off_t lseek(int fildes, off_t offset, int whence);
```
- `fildes` contains the file descriptor
- `offset` is the offset when want to set to 
- `whence` indicates how the seek is performed
