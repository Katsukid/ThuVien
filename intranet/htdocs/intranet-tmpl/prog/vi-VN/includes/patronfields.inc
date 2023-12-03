[%- BLOCK patron_fields -%]
 [%- SWITCH name -%]
 [%- CASE standard -%]<span>Tiêu chuẩn</span>
 [%- CASE full_address -%]<span>Full address</span>
 [%- CASE all_emails -%]<span>All emails</span>
 [%- CASE all_phones -%]<span>All phones</span>
 [%- CASE 'borrowernumber' -%]<span>Borrowernumber</span>
 [%- CASE 'cardnumber' -%]<span>Số thẻ bạn đọc</span>
 [%- CASE 'surname' -%]<span>Họ</span>
 [%- CASE 'firstname' -%]<span>Tên</span>
 [%- CASE 'middle_name' -%]<span>Middle name</span>
 [%- CASE 'title' -%]<span>Lời mở đầu</span>
 [%- CASE 'othernames' -%]<span>Tên khác</span>
 [%- CASE 'initials' -%]<span>Tên biết tắt</span>
 [%- CASE 'pronouns' -%]<span>Pronouns</span>
 [%- CASE 'streetnumber' -%]<span>Số nhà</span>
 [%- CASE 'streettype' -%]<span>Số nhà</span>
 [%- CASE 'address' -%]<span>Địa chỉ</span>
 [%- CASE 'address2' -%]<span>Đơn vị cấp 2</span>
 [%- CASE 'city' -%]<span>Đơn vị cấp 3</span>
 [%- CASE 'state' -%]<span>Bang</span>
 [%- CASE 'zipcode' -%]<span>ZIP/Postal code</span>
 [%- CASE 'country' -%]<span>Khác</span>
 [%- CASE 'email' -%]<span>Thư điện tử chỉnh</span>
 [%- CASE 'phone' -%]<span>Điện thoại chính</span>
 [%- CASE 'mobile' -%]<span>Mobile phone</span>
 [%- CASE 'fax' -%]<span>Số Fax</span>
 [%- CASE 'emailpro' -%]<span>Thư điện tử phụ</span>
 [%- CASE 'phonepro' -%]<span>Điện thoại phụ</span>
 [%- CASE 'B_streetnumber' -%]<span>Alternate street number</span>
 [%- CASE 'B_streettype' -%]<span>Alternate street type</span>
 [%- CASE 'B_address' -%]<span>Địa chỉ thay thế</span>
 [%- CASE 'B_address2' -%]<span>Alternate address line 2</span>
 [%- CASE 'B_city' -%]<span>Alternate city</span>
 [%- CASE 'B_state' -%]<span>Alternate state</span>
 [%- CASE 'B_zipcode' -%]<span>Alternate zip code</span>
 [%- CASE 'B_country' -%]<span>Alternate country</span>
 [%- CASE 'B_email' -%]<span>Alternate email</span>
 [%- CASE 'B_phone' -%]<span>Alternate phone</span>
 [%- CASE 'dateofbirth' -%]<span>Ngày sinh</span>
 [%- CASE 'branchcode' -%]<span>Library (code)</span>
 [%- CASE 'categorycode' -%]<span>Category (code)</span>
 [%- CASE 'dateenrolled' -%]<span>Ngày đăng ký</span>
 [%- CASE 'dateexpiry' -%]<span>Ngày hết hạn</span>
 [%- CASE 'gonenoaddress' -%]<span>Gone no address</span>
 [%- CASE 'lost' -%]<span>Bị mất thẻ</span>
 [%- CASE 'debarred' -%]<span>Bị khóa tài khoản</span>
 [%- CASE 'debarredcomment' -%]<span>Restriction reason</span>
 [%- CASE 'contactname' -%]<span>Guarantor surname</span>
 [%- CASE 'contactfirstname' -%]<span>Guarantor firstname</span>
 [%- CASE 'contacttitle' -%]<span>Guarantor title</span>
 [%- CASE 'guarantorid' -%]<span>Guarantor ID</span>
 [%- CASE 'borrowernotes' -%]<span>Ghi chú lưu thông</span>
 [%- CASE 'relationship' -%]<span>Guarantor relationship</span>
 [%- CASE 'sex' -%]<span>Giới tính</span>
 [%- CASE 'flags' -%]<span>Permissions (code)</span>
 [%- CASE 'userid' -%]<span>Tên người dùng</span>
 [%- CASE 'opacnote' -%]<span>Ghi chú OPAC:</span>
 [%- CASE 'contactnote' -%]<span>Contact note</span>
 [%- CASE 'sort1' -%]<span>Thống kê 1</span>
 [%- CASE 'sort2' -%]<span>Thống kê 2</span>
 [%- CASE 'altcontactfirstname' -%]<span>Alternate contact first name</span>
 [%- CASE 'altcontactsurname' -%]<span>Alternate contact surname</span>
 [%- CASE 'altcontactaddress1' -%]<span>Alternate contact address</span>
 [%- CASE 'altcontactaddress2' -%]<span>Alternate contact address 2</span>
 [%- CASE 'altcontactaddress3' -%]<span>Alternate contact city</span>
 [%- CASE 'altcontactstate' -%]<span>Alternate contact state</span>
 [%- CASE 'altcontactzipcode' -%]<span>Alternate contact ZIP/postal code</span>
 [%- CASE 'altcontactcountry' -%]<span>Alternate contact country</span>
 [%- CASE 'altcontactphone' -%]<span>Alternate contact phone</span>
 [%- CASE 'smsalertnumber' -%]<span>SMS alert number</span>
 [%- CASE 'sms_provider_id' -%]<span>SMS provider</span>
 [%- CASE 'privacy' -%]<span>Privacy (code)</span>
 [%- CASE 'privacy_guarantor_checkouts' -%]<span>Guarantor can view checkouts</span>
 [%- CASE 'updated_on' -%]<span>Lần cập nhật cuối</span>
 [%- CASE 'lastseen' -%]<span>Cập nhật lần cuối</span>
 [%- CASE 'checkprevcheckout' -%]<span>Check previous checkout</span>
 [%- CASE DEFAULT -%]
 [%- END -%]
[%- END -%]
[%- BLOCK patron_fields_dropdown -%]
 [% IF search_box %]
 <label for="searchfieldstype" class="control-label">Trường tìm kiếm</label>
 <select name="searchfieldstype" id="searchfieldstype" class="form-control">
 [% ELSE %]
 <label for="searchfieldstype_filter">Trường tìm kiếm</label>
 <select name="searchfieldstype" id="searchfieldstype_filter">
 [% END %]
 [% SET standard = Koha.Preference('DefaultPatronSearchFields') || 'firstname,middle_name,surname,othernames,cardnumber,userid' %]
 [% SET full_address = 'streetnumber,streettype,address,address2,city,state,zipcode,country' %]
 [% SET all_emails = 'email,emailpro,B_email' %]
 [% SET all_phones = 'phone,phonepro,B_phone,altcontactphone,mobile' %]
 [% default_fields = [ standard, 'surname', 'cardnumber', all_emails, 'borrowernumber', 'userid', all_phones, full_address, 'dateofbirth', 'sort1', 'sort2' ] %]
 [% search_options = default_fields.merge(standard.split(',')).unique %]
 [% FOREACH s_o IN search_options %]
 [% display_name = PROCESS patron_fields name=s_o %]
 [% NEXT IF !display_name %]
 [% IF searchfieldstype == s_o %]
 <option selected="selected" value=[% s_o | html %]>[% display_name | $raw %]</option>
 [% ELSE %]
 <option value=[% s_o | html %]>[% display_name | $raw %]</option>
 [% END %]
 [% END %]
 </select>
[%- END -%]
