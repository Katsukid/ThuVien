[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">Success: Import reverted</div>
 [% END %]
 <table>
 <tr>
 <td>Số lượng bản ghi đã xóa</td>
 <td>[% report.num_deleted | html %]</td>
 </tr>
 <tr>
 <td>Number of records reverted</td>
 <td>[% report.num_reverted | html %]</td>
 </tr>
 <tr>
 <td>Số bản ghi đã bị từ chối</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>Số ĐKCB đã xóa</td>
 <td>[% report.num_items_deleted | html %]</td>
 </tr>
 <tr>
 <td>Number of errors</td>
 <td>[% report.num_errors | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">Manage reverted batch</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
