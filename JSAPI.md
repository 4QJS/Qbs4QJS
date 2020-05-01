# BinaryFile

The `BinaryFile` class allows you to read from and write into binary files.

### OpenMode[](#binaryfile-openmode "Direct link to this headline")

```js
enum BinaryFile.OpenMode { ReadOnly, WriteOnly, ReadWrite }
```

List of modes that a file may be opened in.

The OpenMode values can be combined with the bitwise or operator.

## Available operations[](#available-operations "Direct link to this headline")

### Constructor[](#constructor "Direct link to this headline")

```js
BinaryFile(filePath: string, openMode: OpenMode = BinaryFile.ReadOnly)
```

Opens the file at `filePath` in the given mode and returns the object representing the file.

> **Note:** The mode influences which of the operations listed below can actually be used on the file. If you open a file with `WriteOnly` mode, for example, you won't be able to `read()`. If you open the file with a writable mode, it will be created if it doesn't exist.

### atEof[](#ateof "Direct link to this headline")

```js
atEof(): boolean
```

Returns `true` if no more data can be read from the file, `false` otherwise.

### close[](#close "Direct link to this headline")

```js
close(): void
```

Closes the file. It is recommended to always call this function as soon as you are finished with the file, in order to keep the number of in-flight file descriptors as low as possible.

### filePath[](#filepath "Direct link to this headline")

```js
filePath(): string
```

The absolute path of the file represented by this object.

### size[](#size "Direct link to this headline")

```js
size(): number
```

Returns the size of the file (in bytes).

### resize[](#resize "Direct link to this headline")

```js
resize(size: number): void
```

Sets the file `size` (in bytes). If `size` is larger than the file currently is, the new bytes will be set to 0; if `size` is smaller, the file is truncated.

### pos[](#pos "Direct link to this headline")

```js
pos(): number
```

Returns the position that data is written to or read from.

### seek[](#seek "Direct link to this headline")

```js
seek(pos: number): void
```

Sets the current position to `pos`.

### read[](#read "Direct link to this headline")

```js
read(size: number): number[]
```

Reads at most `size` bytes of data from the file and returns it as an array.

### write[](#write "Direct link to this headline")

```js
write(data: number[]): void
```

Writes `data` into the file at the current position.

---

# Environment

The `Environment` object offers access to the system environment or process environment.

## Available Operations[](#available-operations "Direct link to this headline")

### currentEnv[](#currentenv "Direct link to this headline")

```js
Environment.currentEnv(): { [key: string]: string; }
```

Returns the environment of the current context as an object whose properties are the environment variables.

### getEnv[](#getenv "Direct link to this headline")

```js
Environment.getEnv(key: string): string
```

Tries to find a variable with the given name in the current context's environment and returns its value. If no such variable could be found, `undefined` is returned.

### putEnv[](#putenv "Direct link to this headline")

```js
Environment.putEnv(key: string, value: string): void
```

Sets the value of the environment variable with the given name in the build or run environment.

### unsetEnv[](#unsetenv "Direct link to this headline")

```js
Environment.unsetEnv(key: string): void
```

Unsets the environment variable with the given name from the build or run environment.

---

# File

The `File` object offers limited access to the file system for operations such as copying or removing files.

## Available Operations[](#available-operations "Direct link to this headline")

### copy[](#copy "Direct link to this headline")

```js
File.copy(sourceFilePath: string, targetFilePath: string): boolean
```

Copies `sourceFilePath` to `targetFilePath`. Any directory components in `targetFilePath` that do not yet exist will be created. If `sourceFilePath` is a directory, a recursive copy will be made. If an error occurs, a JavaScript exception will be thrown.

> **Note:** `targetFilePath` must be the counterpart of `sourceFilePath` at the new location, **not** the new parent directory. This allows the copy to have a different name and is true even if `sourceFilePath` is a directory.

### exists[](#exists "Direct link to this headline")

```js
File.exists(filePath: string): boolean
```

Returns true if and only if there is a file at `filePath`.

### directoryEntries[](#directoryentries "Direct link to this headline")

```js
File.directoryEntries(path: string, filter: File.Filter): string[]
```

Returns a sorted list of the directory `path`'s contents non-recursively, filtered by `filter`. The values of `filter` are equivalent to Qt's `QDir::Filter`.

### lastModified[](#lastmodified "Direct link to this headline")

```js
File.lastModified(filePath: string): number
```

Returns the time of last modification for the file at `filePath`. The concrete semantics of the returned value are platform-specific. You should only rely on the property that a smaller value indicates an older timestamp.

### makePath[](#makepath "Direct link to this headline")

```js
File.makePath(path: string): boolean
```

Makes the directory at `path`, creating intermediate directories if necessary. Conceptually equivalent to `mkdir -p`

### move[](#move "Direct link to this headline")

```js
File.move(oldPath: string, newPath: string, overwrite: boolean = true): boolean
```

Renames the file `oldPath` to `newPath`. Returns `true` if successful; otherwise returns `false`. If a file with the name `newPath` already exists, and `overwrite` is `false`, `move()` returns `false` (that is, the file will not be overwritten).

### remove[](#remove "Direct link to this headline")

```js
File.remove(filePath: string): boolean
```

Removes the file at `filePath`. In case of a directory, it will be removed recursively.

# FileInfo

The `FileInfo` object offers various operations on file paths, such as turning absolute paths into relative ones, splitting a path into its components, and so on.

## Available Operations[](#available-operations "Direct link to this headline")

### baseName[](#basename "Direct link to this headline")

```js
FileInfo.baseName(filePath: string): string
```

Returns the file name of `filePath` up to (but not including) the first '.' character.

### canonicalPath[](#canonicalpath "Direct link to this headline")

```js
FileInfo.canonicalPath(filePath: string): string
```

Returns a canonicalized `filePath`, i.e. an absolute path without symbolic links or redundant "." or ".." elements. On Windows, drive substitutions are also resolved.

It is recommended to use `canonicalPath` in only those cases where canonical paths are really necessary. In most cases, `cleanPath` should be enough.

### cleanPath[](#cleanpath "Direct link to this headline")

```js
FileInfo.cleanPath(filePath: string): string
```

Returns `filePath` without redundant separators and with resolved occurrences of `.` and `..` components. For instance, `/usr/local//../bin/` becomes `/usr/bin`.

### completeBaseName[](#completebasename "Direct link to this headline")

```js
FileInfo.completeBaseName(filePath: string): string
```

Returns the file name of `filePath` up to (but not including) the last '.' character.

### completeSuffix[](#completesuffix "Direct link to this headline")

```js
FileInfo.completeSuffix(filePath: string): string
```

Returns the file suffix of `filePath` from (but not including) the last '.' character.

This function was introduced in version 1.12.

### fileName[](#filename "Direct link to this headline")

```js
FileInfo.fileName(filePath: string): string
```

Returns the last component of `filePath`, that is, everything after the last '/' character.

### fromNativeSeparators[](#fromnativeseparators "Direct link to this headline")

```js
FileInfo.fromNativeSeparators(filePath: string): string
```

On Windows hosts, this function behaves the same as [fromWindowsSeparators](jsextension-fileinfo.html#fromwindowsseparators). On other operating systems, it returns the input unmodified.

### fromWindowsSeparators[](#fromwindowsseparators "Direct link to this headline")

```js
FileInfo.fromWindowsSeparators(filePath: string): string
```

Returns `filePath` with all '' characters replaced by '/'.

### isAbsolutePath[](#isabsolutepath "Direct link to this headline")

```js
FileInfo.isAbsolutePath(filePath: string, hostOS?: string[]): boolean
```

Returns true if `filePath` is an absolute path and false if it is a relative one. If `hostOS` is specified, treats `filePath` as a file path of the kind found on that platform. This parameter defaults to the host OS on which Qbs is running and should normally be omitted.

### joinPaths[](#joinpaths "Direct link to this headline")

```js
FileInfo.joinPaths(...paths: string[]): string
```

Concatenates the given paths using the '/' character.

### path[](#path "Direct link to this headline")

```js
FileInfo.path(filePath: string, hostOS?: string[]): string
```

Returns the part of `filePath` that is not the file name, that is, everything up to (but not including) the last '/' character. If `filePath` is just a file name, then '.' is returned. If `filePath` ends with a '/' character, then the file name is assumed to be empty for the purpose of the above definition. If `hostOS` is specified, treats `filePath` as a file path of the kind found on that platform. This parameter defaults to the host OS on which Qbs is running and should normally be omitted.

### relativePath[](#relativepath "Direct link to this headline")

```js
FileInfo.relativePath(dirPath: string, filePath: string): string
```

Returns a relative path so that joining `dirPath` and the returned path results in `filePath`. If necessary, '..' components are inserted. The function assumes `dirPath` and `filePath` to be absolute paths and `dirPath` to be a directory.

### suffix[](#suffix "Direct link to this headline")

```js
FileInfo.suffix(filePath: string): string
```

Returns the file suffix of `filePath` from (but not including) the first '.' character.

This function was introduced in version 1.12.

### toNativeSeparators[](#tonativeseparators "Direct link to this headline")

```js
FileInfo.toNativeSeparators(filePath: string): string
```

On Windows hosts, this function behaves the same as [toWindowsSeparators](jsextension-fileinfo.html#towindowsseparators). On other operating systems, it returns the input unmodified.

### toWindowsSeparators[](#towindowsseparators "Direct link to this headline")

```js
FileInfo.toWindowsSeparators(filePath: string): string
```

Returns `filePath` with all '/' characters replaced by ''.

---

# Process

The `Process` class allows you to start processes, track their output, and so on.

## Available Operations[](#available-operations "Direct link to this headline")

### Constructor[](#constructor "Direct link to this headline")

```js
Process()
```

Allocates and returns a new Process object.

### close[](#close "Direct link to this headline")

```js
close(): void
```

Frees the resources associated with the process. It is recommended to always call this function as soon as you are finished with the process.

### closeWriteChannel[](#closewritechannel "Direct link to this headline")

```js
closeWriteChannel(): void
```

Schedules the stdin channel of process to be closed. The channel will close once all data has been written to the process. After calling this function, any attempts to write to the process will do nothing. See `QProcess::closeWriteChannel()` for more details.

### exec[](#exec "Direct link to this headline")

```js
exec(filePath: string, arguments: string[], throwOnError: boolean): number
```

Executes the program at `filePath` with the given argument list and blocks until the process is finished. If an error occurs (for example, there is no executable file at `filePath`) and `throwOnError` is true, then a JavaScript exception will be thrown. Otherwise (the default), -1 will be returned in case of an error. The normal return code is the exit code of the process.

### exitCode[](#exitcode "Direct link to this headline")

```js
exitCode(): number
```

Returns the exit code of the process. This is needed for retrieving the exit code from processes started via `start()`, rather than `exec()`.

### getEnv[](#getenv "Direct link to this headline")

```js
getEnv(varName: string): string
```

Returns the value of the variable `varName` in the process' environment.

### kill[](#kill "Direct link to this headline")

```js
kill(): void
```

Kills the process, causing it to exit immediately.

### readLine[](#readline "Direct link to this headline")

```js
readLine(): string
```

Reads and returns one line of text from the process output, without the newline character(s).

### atEnd[](#atend "Direct link to this headline")

```js
atEnd(): boolean
```

Returns true if there is no more data to be read from the process output, otherwise returns false.

### readStdErr[](#readstderr "Direct link to this headline")

```js
readStdErr(): string
```

Reads and returns all data from the process' standard error channel.

### readStdOut[](#readstdout "Direct link to this headline")

```js
readStdOut(): string
```

Reads and returns all data from the process' standard output channel.

### setCodec[](#setcodec "Direct link to this headline")

```js
setCodec(codec)
```

Sets the text codec to `codec`. The codec is used for reading and writing from and to the process, respectively. The supported codecs are the same as for `QTextCodec`, for example: "UTF-8", "UTF-16", and "ISO 8859-1".

### setEnv[](#setenv "Direct link to this headline")

```js
setEnv(varName: string, varValue: string): string
```

Sets the value of variable `varName` to `varValue` in the process environment. This only has an effect if called before the process is started.

### setWorkingDirectory[](#setworkingdirectory "Direct link to this headline")

```js
setWorkingDirectory(path: string): void
```

Sets the directory the process will be started in. This only has an effect if called before the process is started.

### start[](#start "Direct link to this headline")

```js
start(filePath: string, arguments: string[]): boolean
```

Starts the program at `filePath` with the given list of arguments. Returns `true` if the process could be started and `false` otherwise.

> **Note:** This call returns right after starting the process and should be used only if you need to interact with the process while it is running. Most of the time, you want to use `exec()` instead.

### terminate[](#terminate "Direct link to this headline")

```js
terminate(): void
```

Tries to terminate the process. This is not guaranteed to make the process exit immediately; if you need that, use `kill()`.

### waitForFinished[](#waitforfinished "Direct link to this headline")

```js
waitForFinished(timeout: number): boolean
```

Blocks until the process has finished or `timeout` milliseconds have passed (default is 30000). Returns true if the process has finished and false if the operation has timed out. Calling this function only makes sense for processes started via `start()` (as opposed to `exec()`).

### workingDirectory[](#workingdirectory "Direct link to this headline")

```js
workingDirectory(): string
```

Returns the directory the process will be started in.

### write[](#write "Direct link to this headline")

```js
write(data: string): void
```

Writes `data` into the process' input channel.

### writeLine[](#writeline "Direct link to this headline")

```js
writeLine(data: string): void
```

Writes `data`, followed by the newline character(s), into the process' input channel.

--- 

# TemporaryDir

The `TemporaryDir` class creates a unique directory for temporary use.

## Available Operations[](#available-operations "Direct link to this headline")

### Constructor[](#constructor "Direct link to this headline")

```js
TemporaryDir()
```

Allocates and returns a new TemporaryDir object. This method creates the temporary directory.

### isValid[](#isvalid "Direct link to this headline")

```js
isValid(): boolean
```

Returns `true` if the temporary directory was created successfully.

### path[](#path "Direct link to this headline")

```js
path(): string
```

Returns the path to the temporary directory. Empty if the temporary directory could not be created.

### remove[](#remove "Direct link to this headline")

```js
remove(): boolean
```

Removes the temporary directory, including all its contents. Returns `true` if removing was successful. It is recommended to always call this function as soon as you are finished with the temporary directory. The directory will not be removed automatically.

---

# TextFile

The `TextFile` class allows you to read from and write into text files.

### TextFile.OpenMode[](#textfile-openmode "Direct link to this headline")

```js
enum TextFile.OpenMode { ReadOnly, WriteOnly, ReadWrite, Append }
```

List of modes that a file may be opened in.

The OpenMode values can be combined with the bitwise or operator.

## Available operations[](#available-operations "Direct link to this headline")

### Constructor[](#constructor "Direct link to this headline")

```js
TextFile(filePath: string, openMode: OpenMode = TextFile.ReadOnly)
```

Opens the file at `filePath` in the given mode and returns the object representing the file.

> **Note:** The mode influences which of the operations listed below can actually be used on the file. If you open a file with `WriteOnly` mode, for example, you won't be able to `read()`. If you open the file with a writable mode, it will be created if it doesn't exist.

### atEof[](#ateof "Direct link to this headline")

```js
atEof(): boolean
```

Returns `true` if no more data can be read from the file, `false` otherwise.

### close[](#close "Direct link to this headline")

```js
close(): void
```


Closes the file. It is recommended to always call this function as soon as you are finished with the file, in order to keep the number of in-flight file descriptors as low as possible.

### filePath[](#filepath "Direct link to this headline")

```js
filePath(): string
```

The absolute path of the file represented by this object.

### readAll[](#readall "Direct link to this headline")

```js
readAll(): string
```


Reads all data from the file and returns it.

### readLine[](#readline "Direct link to this headline")

```js
readLine(): string
```

Reads one line of text from the file and returns it. The returned string does not contain the newline characters.

### setCodec[](#setcodec "Direct link to this headline")

```js
setCodec(codec: string): void
```

Sets the text codec to `codec`. The supported codecs are the same as for `QTextCodec`, for example: "UTF-8", "UTF-16", and "ISO 8859-1".

### truncate[](#truncate "Direct link to this headline")

```js
truncate(): void
```

Truncates the file, that is, gives it the size of zero, removing all content.

### write[](#write "Direct link to this headline")

```js
write(data: string): void
```
Writes `data` into the file at the current position.

### writeLine[](#writeline "Direct link to this headline")

```js
writeLine(data: string): void
```

Writes `data` into the file at the current position and appends the newline character(s).