#!/usr/bin/perl

use Modern::Perl;
use Test::More;
use Test::TCC qw/comp_fail_ok retval/;
use File::Spec::Functions;

my $dir = "t/002-file-opening";

comp_fail_ok(["doesnt_exist.c"], "ERROR: Couldn't open input file, code 2", 
    "Fail on loading nonexistent file");

my @cfiles = map { catfile($dir, "test$_.c") } (1 .. 3);
my @sfiles = map { catfile($dir, "test$_.s") } (1 .. 3);
for my $sfile (@sfiles) {
	if (-e $sfile) {
		unlink($sfile) or die "Couldn't delete $sfile: $!";
	}
}
is(retval("bin/tcc", @cfiles), 0, "Successfully opens existing files");
for my $sfile (@sfiles) {
	ok(-e $sfile, "Assembly file with correct name $sfile created");
}

done_testing;
