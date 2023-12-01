[% USE Koha %]

<div id="navmenu">
 <div id="navmenulist">

 <h5>Hướng dẫn tạo báo cáo</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl">Hướng dẫn tạo báo cáo</a></li>
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Build%20new">Tạo báo cáo mới</a></li>
 [% END %]
 [% IF ( CAN_user_reports_execute_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Use%20saved">Báo cáo được lưu</a></li>
 [% END %]
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?phase=Create%20report%20from%20SQL">Tạo báo cáo từ SQL</a></li>
 [% END %]
 </ul>

 <h5>Báo cáo phân hệ</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">Phân hệ bổ sung</a></li>
 <li><a href="/cgi-bin/koha/reports/borrowers_stats.pl">Bạn đọc</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_stats.pl">Tìm kiếm</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_stats.pl">Phân hệ lưu thông</a></li>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">Ấn phẩm định kỳ</a></li>
 <li><a href="/cgi-bin/koha/reports/cash_register_stats.pl">Cash register</a></li>
 <li><a href="/cgi-bin/koha/reports/reserves_stats.pl">Sách đang giữ</a></li>
 </ul>

 [% IF plugins_enabled %]
 <h5>Report plugins</h5>
 <ul>
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl?method=report">Report plugins</a></li>
 </ul>
 [% END %]

 <h5>Lưu thông nhiều nhất</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/bor_issues_top.pl">Bạn đọc ghi mượn nhiều nhất</a></li>
 <li><a href="/cgi-bin/koha/reports/cat_issues_top.pl">Tài liệu lưu thông nhiều nhất</a></li>
 </ul>

 <h5>Dừng hoạt động</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/borrowers_out.pl">Bạn đọc không ghi mượn</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_out.pl">Tài liệu không lưu thông</a></li>
 </ul>


 <h5>Báo cáo khác</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/itemslost.pl">Tài liệu bị mất</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">Orders by fund</a></li>
 <li><a href="/cgi-bin/koha/reports/manager.pl?report_name=itemtypes">Số bản tài liệu</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_avg_stats.pl">Thời gian ghi mượn trung bình</a></li>
 </ul>
 </div>
</div>
