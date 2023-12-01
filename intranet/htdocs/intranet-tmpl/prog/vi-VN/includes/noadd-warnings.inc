[% IF ( no_add ) %]
 <div class="dialog alert">
 <h3>Không thể tạo tài khoản bạn đọc</h3>
 [% IF ( no_branches ) %]
 <p><strong>Không có thư viện được khai báo. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/branches.pl">Please add a library</a>.[% ELSE %]Cán bộ quản trị phải khai báo ít nhất một thư viện.[% END %]</p>
 [% END %]
 [% IF ( no_categories ) %]
 <p><strong>There are no patron categories defined. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/categories.pl">Please add a patron category</a>.[% ELSE %]Cán bộ quản trị phải khai báo ít nhất một kiểu bạn đọc.[% END %]</p>
 [% END %]
 </div>
[% END %]
