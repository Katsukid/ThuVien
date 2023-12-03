[% INCLUDE 'blocking_errors.inc' %]
[% USE Koha %]
[% USE Branches %]
[% USE Categories %]
[% USE AuthorisedValues %]
[% USE scalar %]
<div id="toolbar" class="btn-toolbar">
 [% IF CAN_user_borrowers_edit_borrowers %]
 <a id="editpatron" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=modify&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | html %]"><i class="fa fa-pencil"></i> Chỉnh sửa</a>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 <a id="changepassword" class="btn btn-default" href="/cgi-bin/koha/members/member-password.pl?member=[% patron.borrowernumber | html %]"><i class="fa fa-lock"></i> Thay đổi mật khẩu</a>
 <a id="duplicate" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=duplicate&amp;borrowernumber=[% patron.borrowernumber | html %]"><i class="fa fa-copy"></i> Sao chép</a>
 [% END %]

 [% IF CAN_user_circulate_circulate_remaining_permissions %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-print"></i> Bản in <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a id="printsummary" href="#">Thông tin tài khoản</a></li>
 <li><a id="printslip" href="#">Thông tin ghi mượn</a></li>
 <li><a id="printquickslip" href="#">Ghi mượn trong ngày</a></li>
 [% IF patron.account_balance != 0 %]
 <li><a id="printfineslip" target="_blank" href="/cgi-bin/koha/members/printnotice.pl?notice=ACCOUNTS_SUMMARY&borrowernumber=[% patron.borrowernumber | uri %]">Print account balance</a></li>
 [% END %]
 [% IF patron.has_overdues %]
 <li><a id="print_overdues" href="#">Print overdues</a></li>
 [% END %]
 <li><a id="printcheckinslip" href="#">Print checkin slip</a></li>
 </ul>
 </div>
 [% END %]

 [% IF ( CAN_user_reserveforothers ) %]
 <a id="searchtohold" class="btn btn-default" href="#"><i class="fa fa-search"></i> Tìm kiếm</a>
 [% END %]

 <a id="addnewmessageLabel" href="#add_message_form" data-toggle="modal" class="btn btn-default"><i class="fa fa-comment-o"></i> Tạo tin nhắn</a>

 [% IF Koha.Preference('CurbsidePickup') %]
 <a id="curbsidePickupLabel" href="/cgi-bin/koha/circ/curbside_pickups.pl?op=find-patron&borrowernumber=[% patron.borrowernumber | html %]" class="btn btn-default"><i class="fa fa-refresh"></i> Schedule pickup</a>
 [% END %]

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown">Thêm <span class="caret"></span></button>
 <ul class="dropdown-menu dropdown-menu-right">
 [% IF CAN_user_borrowers_edit_borrowers %]
 <li><a id="renewpatron" href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | html %]&amp;destination=[% destination | html %]&amp;reregistration=y">Gia hạn tài khoản</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="renewpatron" title="Bạn không được phân quyền để gia hạn tài khoản bạn đọc">Gia hạn tài khoản</a></li>
 [% END %]
 [% IF ( CAN_user_permissions ) %]
 <li><a id="patronflags" href="/cgi-bin/koha/members/member-flags.pl?member=[% patron.borrowernumber | html %]">Phân quyền người dùng</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="patronflags" title="Bạn không được phân quyền để phân quyền chức năng cho bạn đọc">Phân quyền người dùng</a></li>
 [% END %]

 [% IF ( Koha.Preference('TwoFactorAuthentication') == 'enforced' || Koha.Preference('TwoFactorAuthentication') == 'enabled' ) && logged_in_user.borrowernumber == patron.borrowernumber %]
 <li><a id="twofa" href="/cgi-bin/koha/members/two_factor_auth.pl">Manage two-factor authentication</a></li>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers && useDischarge %]
 <li><a href="/cgi-bin/koha/members/discharge.pl?borrowernumber=[% patron.borrowernumber | uri %]">Discharge</a></li>
 [% END %]

 [% IF Koha.Preference('RESTOAuth2ClientCredentials') %]
 [% IF CAN_user_superlibrarian OR loggedinusernumber == patron.borrowernumber %]
 <li><a id="apikeys" href="/cgi-bin/koha/members/apikeys.pl?patron_id=[% patron.borrowernumber | html %]">Manage API keys</a></li>
 [% ELSE %]
 <li class="disabled"><a data-toggle="tooltip" data-placement="left" title="You are not authorized to manage API keys" id="apikeys" href="#">Manage API keys</a></li>
 [% END %]
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 <li><a id="sendwelcome" href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]&op=send_welcome">Send welcome email</a></li>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers && patron.category.effective_reset_password %]
 <li><a id="resetpassword" href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]&op=send_password_reset">Send password reset</a></li>
 [% END %]

 [% IF CAN_user_borrowers_delete_borrowers %]
 <li><a id="deletepatron" href="#">Xóa</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="deletepatron" title="Bạn không được phân quyền để xóa tài khoản bạn đọc">Xóa</a></li>
 [% END %]
 [% SET adult_categories = Categories.scalar.all(category_type => 'A') %]
 [% IF adult_categories.count > 0 %]
 [% IF patron.is_child %]
 <li><a id="updatechild" href="#">Cập nhật Trẻ em - Người lớn</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="updatechild" title="Bạn đọc là người lớn">Cập nhật Trẻ em - Người lớn</a></li>
 [% END %]
 [% END %]
 [% IF Koha.Preference('intranetreadinghistory') %]
 [%IF ( privacy == 2 ) %]
 <li class="disabled"><a data-toggle="tooltip" data-placement="left" title="Not allowed by patron's privacy settings" id="exportbarcodes" href="#">Xuất dữ liệu ghi mượn trong ngày</a></li>
 [% ELSE %]
 <li><a id="exportcheckins" href="#">Xuất dữ liệu ghi mượn trong ngày</a></li>
 [% END %]
 [% END %]
 </ul>
 </div>
</div>

<!-- Modal -->
<div id="add_message_form" class="modal" tabindex="-1" role="dialog" aria-labelledby="addnewmessageLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <form method="post" action="/cgi-bin/koha/circ/add_message.pl" id="message_form" name="message_f">
 <div class="modal-header">
 <h3>Tạo tin nhắn</h3>
 </div>
 <div class="modal-body">
 <div class="form-group">
 <label for="message_type">Gửi tin nhắn cho:</label>
 <select name="message_type" id="message_type">
 <option value="L">Staff - Internal note</option>
 <option value="B">OPAC - [% patron.firstname | html %] [% patron.surname | html %]</option>
 </select>
 </div>
 [% bor_notes = AuthorisedValues.Get( 'BOR_NOTES' ) %]
 [% IF bor_notes %]
 <div class="form-group">
 <label for="select_patron_messages">Nội dung (Chọn theo mẫu hoặc nhập mới): </label>
 <select name="type" id="select_patron_messages">
 <option value="">Chọn ghi chú</option>
 [% FOREACH bor_note IN bor_notes %]
 <option value="[% bor_note.lib | html %]">[% bor_note.lib | html %]</option>
 [% END %]
 </select>
 </div>
 [% END %]
 <div class="form-group">
 <textarea rows="3" class="modal-textarea" name="borrower_message" id="borrower_message" ></textarea>
 </div>
 <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <input type="hidden" name="batch" value="[% batch | html %]" />
 <input type="hidden" name="branchcode" value="[% Branches.GetLoggedInBranchcode | html %]" />
 </div>
 <div class="modal-footer">
 <button class="btn btn-default approve" type="submit"><i class="fa fa-check"></i> Lưu</button>
 <button class="btn btn-default deny cancel" href="#" data-dismiss="modal" aria-hidden="true"><i class="fa fa-times"></i> Hủy bỏ</button>
 </div>
 </form>
 </div>
 </div>
</div>
