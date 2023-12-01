use Modern::Perl;

return {
    bug_number  => "34720",
    description => "Add system preference UpdateNotForLoanStatusOnCheckout",
    up          => sub {
        my ($args) = @_;
        my ( $dbh, $out ) = @$args{qw(dbh out)};

        my $inserted = $dbh->do(
            q{
                INSERT IGNORE INTO systempreferences ( variable, value, options, explanation, type )
                VALUES ('UpdateNotForLoanStatusOnCheckout', '', 'NULL', 'This is a list of value pairs. When an item is checked out, if the not for loan value on the left matches the items not for loan value it will be updated to the right-hand value. E.g. ''-1: 0'' will cause an item that was set to ''Ordered'' to now be available for loan. Each pair of values should be on a separate line.', 'Free')
            }
        );
        say $out ( $inserted == 1 ) ? "Added new system preference 'UpdateNotForLoanStatusOnCheckout'" : "Skipped - System preference exists already in DB"
    },
};
