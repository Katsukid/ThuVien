[% IF ( currency ) %]
 [% IF ( not hide ) %]
 <p><strong>Tiền tệ = [% currency | html %]</strong></p>
 [% END %]
[% ELSE %]
 <div class="dialog alert">
 <h3>Hệ thống chưa có đơn vị tiền tệ chính.</h3>
 [% IF CAN_user_acquisition_currencies_manage %]
 <p><a href="/cgi-bin/koha/admin/currency.pl">Please specify an active currency.</a></p>
 [% ELSE %]
 <p>Your administrator must specify an active currency.</p>
 [% END %]
 </div>
[% END %]
