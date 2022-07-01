#!/usr/bin/perl

# | We expect a source directory to exist.
opendir DIR, 'src'
    or die 'no /src';

# | Will store our list of c files to compile.
my @files = ();

# | Find all C source files and add them to the list of files.
for (;;) {
    my $file = readdir DIR;
    
    last unless $file;
    
    if (!($file =~ /^[.]/) && $file =~ /[.]c$/) {    
        push @files, (substr $file, 0, -2);
    }
}

# | Create an 'obj' directory if one does not already exist.
mkdir 'obj' unless -d 'obj';

# | Compile each .c file in /src to a corresponding .obj file in /obj.
foreach(@files) {
    `gcc src/$_.c -o obj/$_.obj -c`;
}

# | Convert our file names list into full paths to object files.
for (my $i = 0; $i < scalar @files; ++$i) {
    $files[$i] = 'obj/' . $files[$i] . '.obj';
}

# | Create a lib directory unless one already exists.
mkdir 'lib' unless -d 'lib';

# | A string containing all the object file paths delimited by space.
my $s = join ' ', @files;

# | Compile our collection of object files into a single statically linked library.
`ar rcs lib/libcdcmatrix.a $s`;


