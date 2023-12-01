[% USE Koha %]
[% PROCESS 'modal-claims.inc' %]
[% INCLUDE 'format_price.inc' %]

[% IF ( issuecount ) %]
 <div id="issues-table-loading-message">
 <p>
 <a id="issues-table-load-now-button" href="#" class="btn btn-default"><i class="fa fa-book"></i> Show checkouts</a>
 </p>
 </div>
 <form name="issues" action="/cgi-bin/koha/tools/export.pl" method="post">
 <table id="issues-table" style="width: 100% !Important;">
 <thead>
 <tr>
 <th scope="col">&nbsp;</th>
 <th scope="col">&nbsp;</th>
 <th scope="col">Ngày hết hạn</th>
 <th scope="col">Ngày hết hạn</th>
 <th scope="col">Nhan đề</th>
 <th scope="col">Record-level item type</th>
 <th scope="col">Kiểu tài liệu</th>
 <th scope="col">Bộ sưu tập</th>
 <th scope="col">Kho tài liệu</th>
 <th scope="col">Thư viện chính</th>
 <th scope="col">&nbsp;</th>
 <th scope="col">Ngày ghi mượn</th>
 <th scope="col">Nơi ghi mượn</th>
 <th scope="col">Ký hiệu phân loại</th>
 <th scope="col">Số bản sao</th>
 <th scope="col">Phí</th>
 <th scope="col">Tiền phạt</th>
 <th scope="col">Giá tiền</th>
 <th scope="col">Gia hạn <p class="column-tool"><a href="#" id="CheckAllRenewals">Chọn tất cả</a> | <a href="#" id="UncheckAllRenewals">Bất kỳ</a></p></th>
 <th scope="col">Ghi trả <p class="column-tool"><a href="#" id="CheckAllCheckins">Chọn tất cả</a> | <a href="#" id="UncheckAllCheckins">Bất kỳ</a></p></th>
 <th scope="col">Return claims</th>
 <th scope="col">Xuất dữ liệu <p class="column-tool"><a href="#" id="CheckAllExports">Chọn tất cả</a> | <a href="#" id="UncheckAllExports">Bất kỳ</a></p></th>
 </tr>
 </thead>
 [% INCLUDE 'checkouts-table-footer.inc' %]
 </table>

 <label for="issues-table-load-immediately">Always show checkouts automatically</label>
 <input id="issues-table-load-immediately" type="checkbox" />

 <div id="issues-table-actions">
 <fieldset class="action">
 [% IF ( CAN_user_circulate_override_renewals ) %]
 [% IF Koha.Preference( 'AllowRenewalLimitOverride' ) || Koha.Preference( 'AllowRenewalOnHoldOverride' ) %]
 <label for="override_limit">Override renewal restrictions:</label>
 <input type="checkbox" name="override_limit" id="override_limit" value="1" />
 [% END %]
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% IF Koha.Preference( 'UnseenRenewals' ) %]
 <label id="renew_as_unseen_label" for="override_limit">Renew as &quot;unseen&quot; if appropriate:</label>
 <input type="checkbox" name="renew_as_unseen" id="renew_as_unseen_checkbox" value="1" />
 [% END %]
 <button class="btn btn-default" id="RenewCheckinChecked"><i class="fa fa-check"></i> Renew or check in selected items</button>
 <button class="btn btn-default" id="RenewAll"><i class="fa fa-book"></i> Gia hạn tất cả</button>
 [% END %]
 </fieldset>

 [% IF Koha.Preference('ExportCircHistory') %]
 <fieldset>
 <label for="issues-table-output-format"><strong>Xuất dữ liệu ghi mượn theo định dạng:</strong></label>
 <select name="issues-table-output-format" id="issues-table-output-format">
 <option value="iso2709_995">MARC with items</option>
 <option value="iso2709">MARC without items</option>
 [% IF csv_profiles.count %]
 <option value="csv">CSV</option>
 [% END %]
 </select>

 [% IF csv_profiles.count %]
 <select name="csv_profile_id">
 [% FOREACH csv_profile IN csv_profiles %]
 <option value="[% csv_profile.export_format_id | html %]">[% csv_profile.profile | html %]</option>
 [% END %]
 </select>
 [% END %]
 <label for="export_items_bundle_contents">Export items bundle contents</label> <input type="checkbox" name="export_items_bundle_contents" id="export_items_bundle_contents">
 <label for="export_remove_fields">Không xuất trường:</label> <input type="text" id="export_remove_fields" name="export_remove_fields" value="[% Koha.Preference('ExportRemoveFields') | html %]" title="Use for MARC exports" />
 <input type="hidden" name="op" value="export" />
 <input type="hidden" id="output_format" name="output_format" value="iso2709" />
 <input type="hidden" id="dont_export_item" name="dont_export_item" value="0" />
 <input type="hidden" id="record_type" name="record_type" value="bibs" />
 <button class="btn btn-default btn-sm" id="export_submit"><i class="fa fa-download"></i> Xuất dữ liệu</button>
 </fieldset>
 [% END %]
 </div>
 </form>
[% ELSE %]
 <p>Hiện tại bạn đọc không mượn tài liệu của thư viện.</p>
[% END %]

<!-- Claims Returned Modal -->
[% PROCESS 'modal-claims-display' %]
