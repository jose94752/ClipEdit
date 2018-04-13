# Pandoc quick install on Linux Fedora

  Use your package manager for Pandoc on the Fedora repositories you can use either yum or dnf command.

~~~bash
$ su
$ yourroot_password
~~~

and

~~~bash
$ yum install pandoc
~~~

or

~~~bash	
$ dnf install pandoc
~~~


# Linux from targz
[download link](https://github.com/jgm/pandoc/releases/latest)
  
    They provide a binary package for amd64 architecture on the download page. This provides both pandoc and pandoc-citeproc. The executables are statically linked and have no dynamic dependencies or dependencies on external data files. Note: because of the static linking, the pandoc binary from this package cannot use lua filters that require external lua modules written in C.

[Source from Pandoc a universal document converter](https://pandoc.org/installing.html)

#to produce PDF Documentaation
yum install texlive-scheme-full
