[% USE Koha %]
<div id="navmenu">
 <div id="navmenulist">
 <h5>Phân hệ bổ sung</h5>
 <ul>
 <li><a href="/cgi-bin/koha/acqui/acqui-home.pl">Trang chính phân hệ bổ sung</a></li>
 [% IF ( CAN_user_acquisition_order_receive ) %]<li><a href="/cgi-bin/koha/acqui/lateorders.pl">Đơn hàng chậm</a></li>[% END %]
 [% IF ( CAN_user_suggestions_suggestions_manage ) %]<li><a href="/cgi-bin/koha/suggestion/suggestion.pl">Để xuất mua</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/invoices.pl">Hóa đơn</a></li>
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/acqui/edifactmsgs.pl">EDIFACT messages</a></li>
 [% END %]
 </ul>
 [% IF ( CAN_user_reports || CAN_user_circulate_circulate_remaining_permissions ) %]
 <h5>Báo cáo</h5>
 <ul>
 [% IF ( CAN_user_reports ) %]
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">Trình hướng dẫn thống kê chuyển đổi</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">Đặt hàng theo quỹ</a></li>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li><a href="/cgi-bin/koha/circ/reserveratios.pl">Tỉ lệ đặt mượn</a></li>
 [% END %]
 </ul>
 [% END %]
 [% IF ( CAN_user_acquisition_period_manage || CAN_user_acquisition_budget_manage || CAN_user_acquisition_currencies_manage || ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) || CAN_user_parameters_manage_additional_fields ) %]
 <h5>Quản trị hệ thống</h5>
 <ul>
 [% IF ( CAN_user_acquisition_period_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">Ngân sách</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_budget_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">Quỹ</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_currencies_manage ) %]
 <li><a href="/cgi-bin/koha/admin/currency.pl">Tiền tệ</a></li>
 [% END %]
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">EDI accounts</a></li>
 <li><a href="/cgi-bin/koha/admin/edi_ean_accounts.pl">Library EANs</a></li>
 [% END %]
 [% IF CAN_user_acquisition_edit_invoices && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqinvoices">Quản lý các trường hóa đơn</a>
 </li>
 [% END %]
 [% IF CAN_user_acquisition_order_manage && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqbasket">Quản lý trường giỏ hàng</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqorders">Quản lý các trường dòng đơn hàng</a>
 </li>
 [% END %]
 </ul>
 [% END %]
 </div>
</div>
