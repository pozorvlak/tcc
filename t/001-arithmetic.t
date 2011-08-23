#!/usr/bin/perl

use strict;
use warnings;
use Test::More;

sub retval {
	return system(@_) >> 8;
}

sub sfile {
	my $filename = shift;
	$filename =~ s/(.c)?$/.s/;
	return $filename;
}

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
	is(retval("bin/tcc", $infile), 0, "$testname compiled successfully");
	is(retval("gcc", sfile($infile)), 0, "$testname assembled successfully");
	is(retval("./a.out"), $retval, $testname);
}

for my $test (glob("t/001-arithmetic/*.in")) {
	retval_ok($test);
}

done_testing;
