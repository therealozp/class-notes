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

### `fsync()`
the filesystem buffer writes in memory for some time for performance reasons. after that period of time, writes will then be issued to the storage device. this supports the illusion of "fast" writes, but data can be lost if the machine eventually crashes.

however, some applications need an even better guarantee: like DBMS requires force writes from time to time.

`fsync()` forces all **dirty** data to disk for the file referred to the file description. then, it returns once all these writes are complete.

### `rename()`
rename a file to a different name, implemented as an atomic call.
## file links
###  hard link
this is the traditional way that files are managed in the filesystem. that's how the OS links the underlying inode (and thus, metadata) to whatever file name we choose. 

when we do a hard link, we are creating another way to refer the **same file** (i.e. the same inode). so, when we call link:
- creates another name in directory
- point it to the same inode number. **file is not copied**.
- now, we just have two human-readable names that refer to the same file.

 that is the primary reason why file removals call `unlink()`. we do **reference counting**:
 - track how many different file names are linked to this inode
 - when `unlink()` is called, decrement this count
 - if the count reaches 0, the filesystem frees the inode and relevant data blocks (which truly deletes the files)

### symbolic links
generally, much more useful than hard links. 
- hard links cannot link to a directory
- hard links cannot link to another file in another partition, much less another disk. inode numbers are only unique **within a filesystem**.

so, in this case, we can use a soft link, which is another type the file system can know about. it holds the **path name** of the linked to file as data. 

so, creating a new symlink also makes a **new inode!**

