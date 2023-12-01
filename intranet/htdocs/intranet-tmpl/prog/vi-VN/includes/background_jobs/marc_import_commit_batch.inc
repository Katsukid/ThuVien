[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">Bản ghi đã được nhập</div>
 [% END %]
 <table>
 <tr>
 <td>Số lượng bản ghi đã được nhập</td>
 <td>[% report.num_added | html %]</td>
 </tr>
 <tr>
 <td>Số lượng bản ghi được cập nhật</td>
 <td>[% report.num_updated | html %]</td>
 </tr>
 <tr>
 <td>Số bản ghi đã bị từ chối</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>Số lượng ĐKCB đã thêm</td>
 <td>[% report.num_items_added | html %]</td>
 </tr>
 <tr>
 <td>Số tài liệu được thay thế</td>
 <td>[% report.num_items_replaced | html %]</td>
 </tr>
 <tr>
 <td>Number of items ignored</td>
 <td>[% report.num_items_errored | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">Manage imported batch</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
