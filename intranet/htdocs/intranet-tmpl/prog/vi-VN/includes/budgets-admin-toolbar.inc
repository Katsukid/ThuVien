[% INCLUDE 'blocking_errors.inc' %]
<div id="toolbar" class="btn-toolbar">
 [% IF ( budget_period_id ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> Tạo mới <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form">Ngân sách</a></li>
 [% IF ( budget_period_locked || !CAN_user_acquisition_budget_add_del ) %]
 <li class="disabled">
 <a data-toggle="tooltip" data-placement="left" title="The budget is locked" href="#">Quỹ cho [% budget_period_description | html %]</a>
 </li>
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/aqbudgets.pl?op=add_form&amp;budget_period_id=[% budget_period_id | uri %]">Quỹ cho [% budget_period_description | html %]</a>
 </li>
 [% END %]
 </ul>
 </div>

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-pencil"></i> Chỉnh sửa <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form&amp;budget_period_id=[% budget_period_id | uri %]">Chỉnh sửa [% budget_period_description | html %]</a></li>
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=duplicate_form&amp;budget_period_id=[% budget_period_id | uri %]">Sao chép [% budget_period_description | html %]</a></li>
 </ul>
 </div>

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-pencil"></i> Lập kế hoạch <span class="caret"></span></button>
 <ul class="dropdown-menu">
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=MONTHS">Phân bổ theo tháng</a></li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=BRANCHES">Phân bổ theo thư viện</a></li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=ITEMTYPES">Phân bổ theo kiểu tài liệu</a></li>
 [% FOREACH auth_cats_loo IN auth_cats_loop %]
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=[% auth_cats_loo | uri %]">Phân bổ theo [% auth_cats_loo | html %]</a>
 </li>
 [% END %]
 </ul>
 </div>

 [% ELSE %]
 <div class="btn-group"><a class="btn btn-default" id="newrootbudget" href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form"><i class="fa fa-plus"></i> Ngân sách</a></div>
 [% END %]

</div>
