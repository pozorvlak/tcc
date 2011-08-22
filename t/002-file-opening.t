#!/usr/bin/perl

use Modern::Perl;
use Test::More;

is(system("bin/tcc", "doesnt_exist.c") >> 8, 4,
	"Fail on loading nonexistent file");

done_testing;
