[% USE HtmlId %]
<div id="menu">
 <ul>
 [% IF ( accounting ) %]
 <li class="active">
 <a title="Accounting" href="/cgi-bin/koha/admin/preferences.pl?tab=accounting">Thanh toán</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a title="Accounting" href="/cgi-bin/koha/admin/preferences.pl?tab=accounting">Thanh toán</a>
 [% END %]
 [% IF ( acquisitions ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="Phân hệ bổ sung">Phân hệ bổ sung</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="Phân hệ bổ sung">Phân hệ bổ sung</a>
 [% END %]
 </li>

 [% IF ( admin ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=admin" title="Quản trị hệ thống">Quản trị hệ thống</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=admin" title="Quản trị hệ thống">Quản trị hệ thống</a>
 [% END %]
 </li>

 [% IF ( authorities ) %]
 <li class="active">
 <a title="Authority control" href="/cgi-bin/koha/admin/preferences.pl?tab=authorities">Dữ liệu kiểm soát</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a title="Authority control" href="/cgi-bin/koha/admin/preferences.pl?tab=authorities">Dữ liệu kiểm soát</a>
 [% END %]
 </li>

 [% IF ( circulation ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="Phân hệ lưu thông">Phân hệ lưu thông</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="Phân hệ lưu thông">Phân hệ lưu thông</a>
 [% END %]
 </li>

 [% IF ( enhanced_content ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="Thiết lập nội dung nâng cao">NỘI DUNG NÂNG CAO</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="Thiết lập nội dung nâng cao">NỘI DUNG NÂNG CAO</a>
 [% END %]
 </li>

 [% IF ( erm ) %]
 <li class="active">
 <a title="E-resource management" href="/cgi-bin/koha/admin/preferences.pl?tab=erm">E-resource management</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a title="E-resource management" href="/cgi-bin/koha/admin/preferences.pl?tab=erm">E-resource management</a>
 [% END %]
 </li>

 [% IF ( i18n_l10n ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="Thiết lập thông số ngôn ngữ hiển thị">NGÔN NGỮ HIỂN THỊ</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="Thiết lập thông số ngôn ngữ hiển thị">NGÔN NGỮ HIỂN THỊ</a>
 [% END %]
 </li>

 [% IF ( interlibrary_loans ) %]
 <li class="active">
 <a title="Interlibrary loans" href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans">Interlibrary loans</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a title="Interlibrary loans" href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans">Interlibrary loans</a>
 [% END %]
 </li>

 [% IF ( local_use ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/systempreferences.pl">Sử dụng nội bộ</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/systempreferences.pl">Sử dụng nội bộ</a>
 [% END %]
 </li>

 [% IF ( logs ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="Chế độ ghi Log">Nhật ký hệ thống</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="Chế độ ghi Log">Nhật ký hệ thống</a>
 [% END %]
 </li>

 [% IF ( opac ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=opac" title="Thiết lập thông số giao diện OPAC">Giao diện OPAC</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=opac" title="Thiết lập thông số giao diện OPAC">Giao diện OPAC</a>
 [% END %]
 </li>

 [% IF ( patrons ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="Bạn đọc">Bạn đọc</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="Bạn đọc">Bạn đọc</a>
 [% END %]
 </li>

 [% IF ( searching ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="TÌM KIẾM">TÌM KIẾM</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="TÌM KIẾM">TÌM KIẾM</a>
 [% END %]
 </li>

 [% IF ( serials ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="Ấn phẩm định kỳ">Ấn phẩm định kỳ</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="Ấn phẩm định kỳ">Ấn phẩm định kỳ</a>
 [% END %]
 </li>

 [% IF ( staff_interface ) %]
 <li class="active">
 <a title="Staff interface" href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface">Staff interface</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a title="Staff interface" href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface">Staff interface</a>
 [% END %]
 </li>

 [% IF ( tools ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="Công cụ bổ trợ">Công cụ bổ trợ</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="Công cụ bổ trợ">Công cụ bổ trợ</a>
 [% END %]
 </li>

 [% IF ( web_services ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=web_services" title="Thiết lập thông số dịch vụ WEB">Thiết lập thông số dịch vụ WEB</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=web_services" title="Thiết lập thông số dịch vụ WEB">Thiết lập thông số dịch vụ WEB</a>
 [% END %]
 </li>
 </ul>
</div>

[% BLOCK subtabs %]
 [% UNLESS ( searchfield ) %]
 [% FOREACH TAB IN TABS %]
 <ul>
 [% FOREACH LINE IN TAB.LINES %]
 [% IF ( LINE.is_group_title ) %]
 <li><a class="pref_sublink" href="#[% TAB.tab_id | html %]_[% LINE.title | $HtmlId %]">[% LINE.title | html %]</a></li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 [% END %]
[% END %]
