#!/usr/bin/perl

use Modern::Perl;
use Test::More;
use File::Spec::Functions;

my $dir = "t/002-file-opening";

is(system("bin/tcc", "doesnt_exist.c") >> 8, 4,
	"Fail on loading nonexistent file");
my $sfile = catfile($dir, "test1.s");
if (-e $sfile) {
	unlink($sfile) or die "Couldn't delete test1.s: $!";
}
is(system("bin/tcc", catfile($dir, "test1.c")) >> 8, 0,
	"Successfully opens existing file");
ok(-e $sfile, "Assembly file with correct name created");

done_testing;
