#!/usr/bin/perl

use strict;
use warnings;
use Test::More;

sub retval_ok {
	my $infile = shift;
	(my $testname = $infile) =~ s/.in$//;
	open my $fh, "<", $infile;
	my $retval = 0;
	while (<$fh>) {
		if (/expected:\s+(\d+)/) {
			$retval = $1;
			last;
		}
	}
	is(system("bin/tcc", $infile), 0, "$testname compiled successfully");
	is(system("gcc", "ignore_me.s"), 0, "$testname assembled successfully");
	is(system("./a.out"), $retval, $testname);
}

for my $test (glob("t/001-arithmetic/*.in")) {
	retval_ok($test);
}

done_testing;
