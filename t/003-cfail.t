use Modern::Perl;
use Test::More;
use Test::TCC 'comp_fail_ok';

for my $infile (glob("t/003-cfail/*.in")) {
        say $infile;
	(my $testname = $infile) =~ s/.in$//;
	open my $fh, "<", $infile;
	my $error = undef;
	while (<$fh>) {
		if (/error:\s+(.+)/) {
			$error = $1;
			last;
		}
	}
        die "No error message found for $infile" unless defined($error);
        comp_fail_ok $infile, $error, $testname;
}

done_testing;
