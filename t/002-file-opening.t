#!/usr/bin/perl

use Modern::Perl;
use Test::More;
use File::Spec::Functions;

my $dir = "t/002-file-opening";

is(system("bin/tcc", "doesnt_exist.c") >> 8, 4,
	"Fail on loading nonexistent file");
my @cfiles = map { catfile($dir, "test$_.c") } (1 .. 3);
my @sfiles = map { catfile($dir, "test$_.s") } (1 .. 3);
for my $sfile (@sfiles) {
	if (-e $sfile) {
		unlink($sfile) or die "Couldn't delete $sfile: $!";
	}
}
is(system("bin/tcc", @cfiles) >> 8, 0,
	"Successfully opens existing files");
for my $sfile (@sfiles) {
	ok(-e $sfile, "Assembly file with correct name $sfile created");
}

done_testing;
