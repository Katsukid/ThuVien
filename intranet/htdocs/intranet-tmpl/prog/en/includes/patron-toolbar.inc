[% INCLUDE 'blocking_errors.inc' %]
[% USE Categories %]
[% USE Koha %]
[% SET categories = Categories.limited %]

[% UNLESS ( no_add ) %]
<div id="toolbar" class="btn-toolbar">
    <div class="btn-group" id="new-patron-button">
        <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> Thêm bạn đọc <span class="caret"></span></button>
            <ul class="dropdown-menu">
                [% FOREACH category IN categories %]<li><a href="/cgi-bin/koha/members/memberentry.pl?op=add&amp;categorycode=[% category.categorycode | uri %]">[% category.description | html %]</a></li>[% END %]
            </ul>
    </div>
    [% IF Koha.Preference('PatronQuickAddFields') || Koha.Preference('BorrowerMandatoryField') %]
    <div class="btn-group" id="quick-add-new-patron-button">
        <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> Thêm bạn đọc nhanh <span class="caret"></span></button>
            <ul class="dropdown-menu">
                [% FOREACH category IN categories %]<li><a href="/cgi-bin/koha/members/memberentry.pl?op=add&amp;categorycode=[% category.categorycode | uri %]&amp;quickadd=true">[% category.description | html %]</a></li>[% END %]
            </ul>
    </div>
    [% END %]
    [% IF CAN_user_tools_manage_patron_lists %]
        <a class="btn btn-default" href="/cgi-bin/koha/patron_lists/lists.pl" id="patron-lists-button"><i class="fa fa-edit"></i> Danh sách bạn đọc</a>
    [% END %]

</div>
[% END %]
