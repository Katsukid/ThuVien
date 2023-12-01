[% USE Koha %]
[% USE Branches %]
[% PROCESS 'html_helpers.inc' %]
<ol>
 <li><label for="title">Nhan đề: </label> <input type="text" name="title" id="title" value="[% filters.title | html %]" /></li>
 <li><label for="author">Tác giả: </label> <input type="text" name="author" id="author" value="[% filters.author | html %]" /></li>
 <li><label for="isbn">Số ISBN: </label> <input type="text" name="isbn" id="isbn" value="[% filters.isbn | html %]" /></li>
 <li><label for="isbn">Số ISSN: </label> <input type="text" name="issn" id="issn" value="[% filters.issn | html %]" /></li>
 [% IF Koha.Preference('marcflavour') == 'UNIMARC' %]
 <li><label for="ean">EAN: </label> <input type="text" name="ean" id="ean" value="[% filters.ean | html %]" /></li>
 [% END %]
 <li><label for="name">Nhà cung cấp: </label> <input type="text" name="name" id="name" value="[% filters.name | html %]" /></li>
 <li><label for="basket">Giỏ đặt hàng: </label> <input type="text" name="basket" id="basket" value="[% filters.basket | html %]" /></li>
 <li><label for="internalnote">Ghi chú nội bộ:: </label> <input type="text" name="internalnote" id="internalnote" value="[% filters.internalnote | html %]" /></li>
 <li><label for="vendornote">Ghi chú nhà cung cấp: </label> <input type="text" name="vendornote" id="vendornote" value="[% filters.vendornote | html %]" /></li>
 <li><label for="basket_creators">Basket created by: </label>
 <input autocomplete="off" id="find_patron" type="text" class="noEnterSubmit" />
 <div>
 <div id="basket_creators" style="float:left;"></div>
 </div>
 </li>
 <li>
 <label for="managing_library">Managing library: </label>
 <select name="managing_library" id="managing_library">
 <option value="">Tất cả</option>
 [% PROCESS options_for_libraries libraries => Branches.all(selected => '') %]
 </select>
 </li>
 <li><label for="booksellerinvoicenumber ">Vendor invoice number: </label> <input type="text" name="booksellerinvoicenumber" id="booksellerinvoicenumber" value="[% filters.booksellerinvoicenumber | html %]" /></li>
 <li>
 <label for="basketgroupname">Nhóm giỏ đặt hàng:</label>
 <input type="text" name="basketgroupname" id="basketgroupname" value="[% filters.basketgroupname | html %]" />
 </li>
 [% INCLUDE 'additional-fields-entry.inc' available=available_additional_fields values=additional_field_filters wrap_fieldset=0 %]
 <li>
 <label for="ordernumber">Số đơn hàng:</label>
 <input type="text" name="ordernumber" id="ordernumber" value="[% filters.ordernumber | html %]" />
 <label class="yesno" for="search_children_too">
 [% IF filters.search_children_too %]
 <input type="checkbox" name="search_children_too" id="search_children_too" value="1" checked="checked" />
 [% ELSE %]
 <input type="checkbox" name="search_children_too" id="search_children_too" value="1" />
 [% END %]
 Display children too
 </label>
 </li>

 <li>
 <label for="orderstatus">Trạng thái: </label>
 <select name="orderstatus" id="orderstatus">
 [% IF filters.orderstatus == "" %]
 <option value="">Tất cả trừ trạng thái "Bị hủy bỏ"</option>
 [% ELSE %]
 <option value="" selected="selected"></option>
 [% END %]
 [% IF filters.orderstatus == "new" %]
 <option value="new" selected="selected">Tạo mới</option>
 [% ELSE %]
 <option value="new">Tạo mới</option>
 [% END %]
 [% IF filters.orderstatus == "ordered" %]
 <option value="ordered" selected="selected">Đặt hàng</option>
 [% ELSE %]
 <option value="ordered">Đặt hàng</option>
 [% END %]
 [% IF filters.orderstatus == "partial" %]
 <option value="partial" selected="selected">Nhận một phần đơn hàng</option>
 [% ELSE %]
 <option value="partial">Nhận một phần đơn hàng</option>
 [% END %]
 [% IF filters.orderstatus == "complete" %]
 <option value="complete" selected="selected">Nhận</option>
 [% ELSE %]
 <option value="complete">Nhận</option>
 [% END %]
 [% IF filters.orderstatus == "cancelled" %]
 <option value="cancelled" selected="selected">Hủy bỏ</option>
 [% ELSE %]
 <option value="cancelled">Hủy bỏ</option>
 [% END %]
 </select>
 <label class="yesno" for="search_children_too">
 [% IF filters.is_standing %]
 <input type="checkbox" name="is_standing" id="is_standing" value="1" checked="checked" />
 [% ELSE %]
 <input type="checkbox" name="is_standing" id="is_standing" value="1" />
 [% END %]
 Standing order
 </label>
 </li>
 <li>
 <label for="fund">Nguồn quỹ: </label>
 <select name="budget" id="fund">
 <option value="">Tất cả quỹ</option>
 [% FOREACH bp_loo IN bp_loop %]
 <optgroup label="[% bp_loo.budget_period_description | html %]">
 [% FOREACH h_loo IN bp_loo.hierarchy %]
 [% IF h_loo.budget_id == filters.budget %]
 <option type="text" value="[% h_loo.budget_id | html %]" branchcode="[% h_loo.budget_branchcode | html %]" selected="selected">
 [% ELSE %]
 <option type="text" value="[% h_loo.budget_id | html %]" branchcode="[% h_loo.budget_branchcode | html %]">
 [% END %]
 [% h_loo.budget_display_name | html %]
 </option>
 [% END %]
 </optgroup>
 [% END %]
 </select>
 </li>

 <li><label for="from">Từ: </label>
 <input type="text" size="10" id="from" name="from" value="[% filters.from_placed_on | html %]" class="flatpickr" data-date_to="to" />
 <div class="hint">[% INCLUDE 'date-format.inc' %]</div>
 </li>
 <li><label for="to">Đến ngày: </label>
 <input type="text" size="10" id="to" name="to" value="[% filters.to_placed_on | html %]" class="flatpickr" />
 <div class="hint">[% INCLUDE 'date-format.inc' %]</div>
 </li>
</ol>
