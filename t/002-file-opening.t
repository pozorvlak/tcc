#!/usr/bin/perl

use Modern::Perl;
use Test::More;
use Capture::Tiny 'capture';
use File::Spec::Functions;
use autodie;

sub comp_fail_ok {
    my ($system_args, $err_msg, $name) = @_;
    my ($out, $err) = capture { system @$system_args };
    ok $err =~ qr/$err_msg/, $name;
}

my $dir = "t/002-file-opening";

comp_fail_ok(["bin/tcc", "doesnt_exist.c"],
    "ERROR: Couldn't open input file, code 2", 
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
