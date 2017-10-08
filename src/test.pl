my $t1;
my $t2;
my $i = 0;
my $x = 2_000_000_000;

$t1 = time;

while ($i != $x) {
    ++$i;    
}
    
$t2 = time;
print 'diff: ' . ($t2 . ', ' . $t1);

print $x. ', ' . $i;