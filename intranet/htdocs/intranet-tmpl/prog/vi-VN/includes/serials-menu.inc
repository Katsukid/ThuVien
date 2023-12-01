<div id="navmenu">
 <div id="navmenulist">
 <h5>Ấn phẩm định kỳ</h5>
 <ul>
 [% IF ( subscriptionid ) %]
 <li><a href="/cgi-bin/koha/serials/serials-collection.pl?subscriptionid=[% subscriptionid | uri %]">Bộ sưu tập APĐK</a></li>
 [% UNLESS closed %]
 [% IF ( routing && CAN_user_serials_routing ) %]
 [% IF ( hasRouting ) %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]">Chỉnh sửa danh sách nhận ÂPĐK</a></li>
 [% ELSE %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]&amp;op=new">Tạo danh sách nhận</a></li>
 [% END %]
 [% END %]
 [% END %]
 [% END %]

 [% IF ( CAN_user_serials_claim_serials ) %]
 <li><a href="/cgi-bin/koha/serials/claims.pl">Khiếu nại</a></li>
 [% END %]
 [% IF ( CAN_user_serials_check_expiration ) %]
 <li><a href="/cgi-bin/koha/serials/checkexpiration.pl">Kiểm tra ÂPĐK quá hạn</a></li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/serials/subscription-frequencies.pl">
 Quản lý tần suất </a>
 </li>
 <li>
 <a href="/cgi-bin/koha/serials/subscription-numberpatterns.pl">
 Quản lý mẫu đánh số ÂPĐK </a>
 </li>
 [% IF Koha.Preference('Mana') == 1 %]
 <li><a href="/cgi-bin/koha/serials/serials-search.pl?mana=1">Search on Mana</a></li>
 [% END %]
 [% IF CAN_user_serials_edit_subscription && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=subscription">Manage subscription fields</a>
 </li>
 [% END %]
 </ul>

 [% IF ( CAN_user_reports ) %]
 <h5>Báo cáo</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">Serials statistics wizard</a></li>
 </ul>
 [% END %]

 </div>
</div>
