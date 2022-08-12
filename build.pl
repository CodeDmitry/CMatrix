#!/usr/bin/perl

# | Attempt to open the 'src' directory as DIR, 
# |     terminate if we cannot find it or 
# |     if we cannot open it.
my $open_source_dir_result = opendir(DIR, 'src');
if ($open_source_dir_result == 0) {
    die('The /src directory cannot be opened or does not exist.');
}

# | List of C file names to compile.
my @files = ();

# | Find all C source files and add them to the list of files.
# TODO: deobfuscate, section has excessive reading complexity.
for (;;) {
    # | readdir returns undef if we have finished reading all the files.
    my $fileName = readdir(DIR);
    
    # | if $fileName is undef, we are done making our list.
    last unless $fileName;
    
    # | Make sure we only add the file to the list
    # |     if it is a c file. 
    if (!($fileName =~ /^[.]/) && $fileName =~ /[.]c$/) {    
        my $filenameWithoutExtension = substr($fileName, 0, -2); 
        push @files, $filenameWithoutExtension;
    }
}

# | We are done enumerating the source directory. 
closedir(DIR);

# Create an 'obj' directory unless it already exists.
if (!(-d 'obj')) {
    mkdir('obj');
}

# | Use gcc to compile
# |     each .c file in '/src' to a corresponding '.obj' file in '/obj'.
foreach(@files) {
    `gcc src/$_.c -o obj/$_.obj -c`;
}

# | Convert our file names list into full paths to object files.
for (my $i = 0; $i < scalar(@files); ++$i) {
    $files[$i] = 'obj/' . $files[$i] . '.obj';
}

# | Create a 'lib' directory unless it already exists.
if (!(-d 'lib')) {
    mkdir('lib') 
}

# | A string containing all the object file paths delimited by space.
my $s = join(' ', @files);

# | Compile our collection of object files into a 
# |     static library.
`ar rcs lib/libcdcmatrix.a $s`;


