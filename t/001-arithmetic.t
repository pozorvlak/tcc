#!/usr/bin/perl

use strict;
use warnings;
use Test::More 'no_plan';

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
	is(system("tcc", $infile), 0, "$testname compiled successfully");
	is(system("./a.out"), $retval, $testname);
}

for my $test (glob("001-integer-arithmetic/*.in")) {
	retval_ok($test);
}

done_testing;
