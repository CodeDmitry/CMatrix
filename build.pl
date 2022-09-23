#!/usr/bin/perl
# | This Perl script automates compiling each file
# |     in the src directory to the obj directory,
# |     then uses them to create the lib file in
# |     the lib directory.

# | Attempt to open the 'src' directory as DIR, 
# |     terminate if we cannot find it or 
# |     if we cannot open it.
my $open_source_dir_result = opendir(DIR, 'src');
if ($open_source_dir_result == 0) {
    die (
        'The /src directory cannot be '
        . 'opened or does not exist.'
    );
}

# | A list which will be used to store the names of the 
# |     C files to be compiled. 
my @cfiles = ();

# | Find all C source files and add them to the list of 
# |     files.
for (;;) {
    # | readdir returns undef if we have finished reading 
    # |     all the files.
    my $fileName = readdir(DIR);
    
    # | if $fileName is undef, we are done making our list.
    last unless $fileName;
    
    # | Make sure we only add the file to the list
    # |     if it is a c file. 
    if (!($fileName =~ /^[.]/) && $fileName =~ /[.]c$/) {    
        my $filenameWithoutExtension 
            = substr($fileName, 0, -2)
            ; 
        push(@cfiles, $filenameWithoutExtension);
    }
}

# | We are done enumerating the source directory. 
closedir(DIR);

# Create an 'obj' directory unless it already exists.
if (!(-d 'obj')) {
    mkdir('obj');
}

# | Use gcc to compile each .c file in '/src' to 
# |     a corresponding '.obj' file in '/obj'.
foreach(@cfiles) {
    `gcc src/$_.c -o obj/$_.obj -c`;
}

# | Convert our file names list into full paths 
# |     to object files.
for (my $i = 0; $i < scalar(@cfiles); ++$i) {
    $cfiles[$i] = 'obj/' . $cfiles[$i] . '.obj';
}

# | Create a 'lib' directory unless it already exists.
if (!(-d 'lib')) {
    mkdir('lib') 
}

# | A string containing all the object file paths 
# |     delimited by space.
my $space_delimited_c_files = join(' ', @cfiles);

# | Compile our collection of object files into a 
# |     static library.
`ar rcs lib/libcdcmatrix.a $space_delimited_c_files`;


