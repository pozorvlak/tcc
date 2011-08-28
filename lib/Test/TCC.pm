package Test::TCC;

=pod

=head1 NAME

Test::TCC - Test functions for my toy compiler

=head1 SYNOPSIS

   use Test::More;
   use Test::TCC qw/comp_fail_ok/;

   comp_fail_ok ["broken_program.c"], "error message here", "test name here";

   done_testing;

=cut

require Test::More;
use Capture::Tiny 'capture';
require Exporter;
@ISA = qw/Exporter/;
@EXPORT_OK = qw/comp_fail_ok/;

our $tcc_path = "bin/tcc";

sub comp_fail_ok {
    my ($tcc_args, $err_msg, $name) = @_;
    my ($out, $err) = capture { system $tcc_path, @$tcc_args };
    Test::More::ok $err =~ qr/$err_msg/, $name;
}

1;
