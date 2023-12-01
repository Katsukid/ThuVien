<nav id="shortcut" class="shortcut">
    [% IF Koha.Preference('showLastPatron') %]
        [% INCLUDE 'last-borrower.inc' %]
    [% END %]

</nav>
