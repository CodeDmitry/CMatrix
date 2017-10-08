use Data::Dumper;
$Data::Dumper::Terse = 1;
$Data::Dumper::Deparse = 1;

opendir DIR, 'src'
    or die 'no /src';

@files = ();
        
for (;;) {
    my $file = readdir DIR;
    
    last unless $file;
    
    if (!($file =~ /^[.]/) && $file =~ /[.]c$/) {    
        push @files, (substr $file, 0, -2);
    }
}

mkdir 'obj' unless -d 'obj';

foreach(@files) {
    `gcc src/$_.c -o obj/$_.obj -c`;
}

for (my $i = 0; $i < scalar @files; ++$i) {
    $files[$i] = 'obj/' . $files[$i] . '.obj';
}

mkdir 'lib' unless -d 'lib';

$s = join ' ', @files;

`ar rcs lib/libmatrix.a $s`;


