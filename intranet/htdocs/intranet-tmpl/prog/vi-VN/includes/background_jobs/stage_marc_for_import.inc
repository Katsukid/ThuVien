[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">Completed staging records</div>
 [% END %]

 <h2>MARC staging results</h2>
 [% SWITCH job.decoded_data.record_type %]
 [% CASE 'biblio' %]
 <h3>Đang xử lý biểu ghi thư mục</h3>
 [% CASE 'auth' %]
 <h3>Đang xử lý biểu ghi nhất quán</h3>
 [% END %]
 <ul>
 <li>[% report.total | html %] biểu ghi trong tệp tin dữ liệu</li>
 <li>[% report.import_errors | html %] biểu ghi không được duyệt do lỗi MARC</li>
 <li>[% report.staged | html %] biểu ghi được duyệt</li>
 [% IF ( report.checked_matches ) %]
 <li>[% report.matched | html %] biểu ghi có ít nhật một tiêu chí phù hợp với quy tắc kiểm tra &quot;[% report.matcher_code | html %]&quot;</li>
 [% ELSE %]
 [% IF ( report.matcher_failed ) %]
 <li>Biểu ghi lỗi_Không phù hợp quy tắc kiểm tra.</li>
 [% ELSE %]
 <li>Không phù hợp với biểu ghi hiện tại trong biên mục</li>
 [% END %]
 [% END %]
 [% IF report.record_type == 'biblio' %]
 <li>Tìm thấy [% report.num_items | html %] bản tài liệu và đã được duyệt</li>
 [% END %]
 [% IF ( report.label_batch ) %]
 <li>Lô nhãn gáy được tạo: Số [% report.label_batch | html %] </li>
 [% END %]
 </ul>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | uri %]">View batch</a>
 </p>
 [% IF report.basket_id && report.vendor_id %]
 <p>
 <a id="addtobasket" class="btn btn-default" href="/cgi-bin/koha/acqui/addorderiso2709.pl?import_batch_id=[% report.import_batch_id | html %]&basketno=[% report.basket_id | html %]&booksellerid=[% report.vendor_id | html %]">Add staged files to basket</a>
 </p>
 [% END %]
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
