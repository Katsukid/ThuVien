[% USE Koha %]
[% SET hold_cancellation = AuthorisedValues.GetAuthValueDropbox('HOLD_CANCELLATION') %]
[% USE AuthorisedValues %]
<table class="holds_table">
 <thead>
 <tr>
 <th><input type="checkbox" class="select_hold_all"/></th>
 <th>Thứ tự đặt mượn</th>
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 <th>&nbsp;</th>
 [% END %]
 <th>Bạn đọc</th>
 <th>Ghi chú</th>
 <th>Thời gian</th>
 <th>Ngày hết hạn</th>
 <th>Thư viện nhận tài liệu</th>
 <th>Thông tin cá nhân</th>
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 <th>
 <i class="fa fa-lg fa-rotate-90 fa-fast-forward" title="Chuyển thành đặt mượn có mức ưu tiên thấp nhất"></i>
 </th>
 [% END %]
 <th>&nbsp;</th>
 <th>&nbsp;</th>
 <th>Print hold/transfer slip</th>
 </tr>
 </thead>
 [%- SET first_priority = 0 -%]
 [%- SET found_holds = 0 -%]
 [%- SET last_priority  = holds.last.priority -%]

 [% BLOCK priority_dropdown %]
 [%- SET loop_priority = 1 -%]
 [%- WHILE loop_priority <= last_priority -%]
 [%- IF this_priority == loop_priority -%]
 <option value="[% loop_priority | html %]" selected="selected">[% loop_priority | html %]</option>
 [%- ELSE -%]
 <option value="[% loop_priority | html %]">[% loop_priority | html %]</option>
 [%- END -%]
 [%- loop_priority = loop_priority + 1- %]
 [%- END -%]
 [% END %]

 [% FOREACH hold IN holds %]
 [%- IF !hold.found && first_priority == 0 -%]
 [%- first_priority = hold.priority -%]
 [%- found_holds = loop.index() -%]
 [%- END -%]
 [%- IF Koha.Preference('HoldsSplitQueueNumbering') == 'actual' -%]
 [%- this_priority = hold.priority -%]
 [%- ELSE -%]
 [%- this_priority = loop.count() - found_holds -%]
 [%- END -%]
 [% IF hold.suspend %]
 <tr class="suspend">
 [% ELSE %]
 <tr>
 [% END %]
 <td><input type="checkbox" class="select_hold" data-id="[% hold.reserve_id | html %]"/></td>
 <td>
 <input type="hidden" name="reserve_id" value="[% hold.reserve_id | html %]" />
 <input type="hidden" name="borrowernumber" value="[% hold.borrowernumber | html %]" />
 <input type="hidden" name="biblionumber" value="[% hold.biblionumber | html %]" />
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 [% IF Koha.Preference('HoldsSplitQueue') == "nothing" && !hold.found %]
 <select name="rank-request" class="rank-request" data-hold-id="[% hold.reserve_id | html %]">
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 [% PROCESS priority_dropdown %]
 [% ELSE %]
 <option value="[% hold.priority | html %]" selected="selected">[% this_priority | html %]</option>
 [% END %]
 <option value="del">Xóa</option>
 </select>
 [% ELSE %]
 <input type="hidden" name="rank-request" class="rank-request" value="[% hold.priority | html %]" data-hold-id="[% hold.reserve_id | html %]">
 <select name="rank-request" class="rank-request" disabled="disabled" data-hold-id="[% hold.reserve_id | html %]">
 [% IF ( hold.found ) %]
 [% IF ( hold.intransit ) %]
 <option value="T" selected="selected">Đang vận chuyển</option>
 [% ELSIF (hold.inprocessing) %]
 <option value="P" selected="selected">In processing</option>
 [% ELSE %]
 <option value="W" selected="selected">Đang chờ</option>
 [% END %]
 [% ELSE %]
 <option value="[% hold.priority | html %]" selected="selected">[% this_priority | html %]</option>
 [% END %]
 </select>
 [% END %]
 [% ELSE %]
 <input type="hidden" name="rank-request" class="rank-request" value="[% hold.priority | html %]" data-hold-id="[% hold.reserve_id | html %]">
 [% hold.priority | html %]
 [% END %]
 </td>
 [%- IF ( CAN_user_reserveforothers_modify_holds_priority ) -%]
 [%- UNLESS hold.found -%]
 [%- SET prev_priority  = loop.prev.priority -%]
 [%- SET next_priority  = loop.next.priority -%]
 <td style="white-space:nowrap;">
 <a class="hold-arrow" href="request.pl?action=move&where=up&first_priority=[% first_priority | html %]&last_priority=[% last_priority | html %]&prev_priority=[% prev_priority | html %]&next_priority=[% next_priority | html %]&borrowernumber=[% hold.borrowernumber | html %]&biblionumber=[% hold.biblionumber | html %]&reserve_id=[% hold.reserve_id | html %]&date=[% hold.date | html %]" title="Di chuyển lên">
 <i class="fa fa-lg icon-move-hold-up" aria-hidden="true"></i>
 </a>

 <a class="hold-arrow" href="request.pl?action=move&where=top&first_priority=[% first_priority | html %]&last_priority=[% last_priority | html %]&prev_priority=[% prev_priority | html %]&next_priority=[% next_priority | html %]&borrowernumber=[% hold.borrowernumber | html %]&biblionumber=[% hold.biblionumber | html %]&reserve_id=[% hold.reserve_id | html %]&date=[% hold.date | html %]" title="Lên trên cùng">
 <i class="fa fa-lg icon-move-hold-top" aria-hidden="true"></i>
 </a>

 <a class="hold-arrow" href="request.pl?action=move&where=bottom&first_priority=[% first_priority | html %]&last_priority=[% last_priority | html %]&prev_priority=[% prev_priority | html %]&next_priority=[% next_priority | html %]&borrowernumber=[% hold.borrowernumber | html %]&biblionumber=[% hold.biblionumber | html %]&reserve_id=[% hold.reserve_id | html %]&date=[% hold.date | html %]" title="Xuống dưới cùng">
 <i class="fa fa-lg icon-move-hold-bottom" aria-hidden="true"></i>
 </a>

 <a class="hold-arrow" href="request.pl?action=move&where=down&first_priority=[% first_priority | html %]&last_priority=[% last_priority | html %]&prev_priority=[% prev_priority | html %]&next_priority=[% next_priority | html %]&borrowernumber=[% hold.borrowernumber | html %]&biblionumber=[% hold.biblionumber | html %]&reserve_id=[% hold.reserve_id | html %]&date=[% hold.date | html %]" title="Di chuyển xuống">
 <i class="fa fa-lg icon-move-hold-down" aria-hidden="true"></i>
 </a>
 </td>
 [%- ELSE -%]
 <td></td>
 [%- END -%]
 [%- END -%]
 <td>
 [% INCLUDE 'patron-title.inc' patron=hold.patron hide_patron_infos_if_needed=1 %]
 </td>
 <td>[% hold.notes | html | html_line_break %]</td>
 <td>
 [% IF Koha.Preference('AllowHoldDateInFuture') %]
 <input type="text" class="flatpickr" value="[% hold.date | html %]" required="required" size="10" name="reservedate" />
 [% ELSE %]
 [% hold.date | $KohaDates %]
 [% END %]
 </td>
 <td>
 [% UNLESS hold.expired %]
 <input type="text" class="flatpickr" data-flatpickr-futuredate="true" value="[% hold.expirationdate | html %]" size="10" name="expirationdate" />
 [% ELSE %]
 <span class="expiredon"><label>Expired:</label> [% hold.expirationdate | $KohaDates %]</span>
 [% END %]
 </td>
 <td>
 [%- IF ( hold.found ) -%]
 <input type="hidden" name="pickup" value="[% hold.wbrcode | html %]" />
 [%- IF ( hold.atdestination ) -%]
 Item waiting at <strong> [% hold.wbrname | html %]</strong>[% IF hold.desk_name %], [% hold.desk_name | html %],[% END %] since [% hold.waiting_date | $KohaDates %]
 [%- ELSIF (hold.intransit) -%]
 Item being transferred to <strong> [% hold.wbrname | html %]</strong>
 [%- ELSIF (hold.inprocessing) -%]
 Item being processed at <strong> [% hold.wbrname | html %]</strong>
 [%- ELSE -%]
 Hold expected at <strong>[% hold.wbrname | html %]</strong>, please checkin to verify status
 [%- END -%]
 [%- ELSE -%]
 [%- IF Koha.Preference('IndependentBranches') && Branches.all().size == 1 -%]
 [% Branches.GetName(hold.branchcode) | html %] <input type="hidden" name="pickup" value="[% hold.branchcode | html %]" />
 [%- ELSE -%]
 <select class="pickup_location_dropdown"
                                data-selected="[% hold.branchcode | html %]"
                                data-hold-id="[% hold.reserve_id | html %]"
                                data-pickup-location-source="hold"
                                name="pickup">
 <option selected="selected" value="[% hold.branchcode | html %]">[% Branches.GetName(hold.branchcode) | html %]</option>
 <option value="" disabled="disabled" class="loading">Đang tải...</option>
 </select>
 <img class="loading_[% hold.reserve_id | html %]" src="[% interface | html %]/[% theme | html %]/img/spinner-small.gif" alt="" style="display:none;"/>
 [%- END -%]
 [%- END -%]
 </td>
 <td>
 [%- IF ( hold.found ) -%]
 <a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% hold.biblionumber | uri %]&amp;itemnumber=[% hold.itemnumber | uri %]#item[% hold.itemnumber | uri %]">
 [%- IF ( hold.barcodenumber ) -%]
 [%- hold.barcodenumber | html -%]
 <input type="hidden" name="itemnumber" value="[% hold.itemnumber | html %]" />
 [%- ELSE -%]
 <span>No barcode</span>
 [%- END -%]
 </a>
 [%- ELSE -%]
 [%- IF ( hold.item_level_hold ) -%]
 <em>
 <span>Only item</span>
 <a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% hold.biblionumber | uri %]&amp;itemnumber=[% hold.itemnumber | uri %]#item[% hold.itemnumber | uri %]">
 [%- IF ( hold.barcodenumber ) -%]
 [%- hold.barcodenumber | html -%]
 <input type="hidden" name="itemnumber" value="[% hold.itemnumber | html %]" />
 [%- ELSE -%]
 <span>No barcode</span>
 [%- END -%]
 </a>
 </em>
 [%- ELSE -%]
 [%- IF hold.itemtype -%]
 <em>Next available [% ItemTypes.GetDescription( hold.itemtype ) | html %] item</em>
 [%- ELSIF hold.object.item_group -%]
 <em>Next available item from group <strong>[% hold.object.item_group.description | html %]</strong></em>
 [%- ELSE -%]
 <em>Tài liệu sẵn sàng tiếp theo</em>
 [%- END -%]

 <input type="hidden" name="itemnumber" value="" />
 [%- END -%]
 [%- END -%]
 [%- IF hold.non_priority -%]
 <br><i>Non priority hold</i>
 [%- END -%]
 </td>
 [%- IF ( CAN_user_reserveforothers_modify_holds_priority ) -%]
 [%- UNLESS hold.found -%]
 <td>
 [% IF ( hold.lowestPriority ) %]
 <a class="hold-arrow" title="Remove lowest priority" href="request.pl?action=setLowestPriority&amp;borrowernumber=[% hold.borrowernumber | html %]&amp;biblionumber=[% hold.biblionumber | html %]&amp;reserve_id=[% hold.reserve_id | html %]&amp;date=[% hold.date | html %]">
 <i class="fa fa-lg fa-rotate-90 icon-unset-lowest" aria-hidden="true"></i>
 [% ELSE %]
 <a class="hold-arrow" title="Set lowest priority" href="request.pl?action=setLowestPriority&amp;borrowernumber=[% hold.borrowernumber | html %]&amp;biblionumber=[% hold.biblionumber | html %]&amp;reserve_id=[% hold.reserve_id | html %]&amp;date=[% hold.date | html %]">
 <i class="fa fa-lg fa-rotate-90 icon-set-lowest" aria-hidden="true"></i>
 [% END %]
 </a>
 </td>
 [%- ELSE -%]
 <td></td>
 [%- END -%]
 [%- END -%]
 <td>
 <a class="cancel-hold" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-id="[% hold.reserve_id | html %]" href="request.pl?action=cancel&borrowernumber=[% hold.borrowernumber | html %]&biblionumber=[% hold.biblionumber | html %]&reserve_id=[% hold.reserve_id | html %]&date=[% hold.date | html %]" title="Hủy đặt mượn">
 <i aria-label="Hủy đặt mượn" class="fa fa-trash"></i>
 </a>
 </td>
 <td>
 [% IF Koha.Preference('SuspendHoldsIntranet') %]
 [% UNLESS ( hold.found ) %]
 <button class="btn btn-default btn-xs toggle-suspend" data-reserve-id="[% hold.reserve_id | html %]" data-biblionumber="[% hold.biblionumber | html %]">
 [% IF ( hold.suspend ) %]
 <i class="fa fa-play" aria-hidden="true"></i> Unsuspend
 [% ELSE %]
 <i class="fa fa-pause" aria-hidden="true"></i> Suspend
 [% END %]
 </button>

 [% IF Koha.Preference('AutoResumeSuspendedHolds') %]
 <label for="suspend_until_[% hold.reserve_id | html %]">[% IF ( hold.suspend ) %] trên [% ELSE %] tới ngày [% END %]</label>
 <input type="text" name="suspend_until_[% hold.reserve_id | html %]" id="suspend_until_[% hold.reserve_id | html %]" size="10" value="[% hold.suspend_until | html %]" class="flatpickr" data-flatpickr-futuredate="true" />
 [%- ELSE -%]
 <input type="hidden" name="suspend_until_[% hold.reserve_id | html %]" id="suspend_until_[% hold.reserve_id | html %]" value=""/>
 [%- END -%]
 [%- END -%]
 [%- END # IF SuspendHoldsIntranet -%]
 [%- IF ( hold.found ) -%]
 <input id="revert_hold_[% hold.reserve_id | html %]" onclick="window.location.href='request.pl?action=move&where=down&first_priority=[% first_priority | uri %]&last_priority=[% last_priority | uri %]&prev_priority=0&next_priority=1&borrowernumber=[% hold.borrowernumber | uri %]&biblionumber=[% hold.biblionumber | uri %]&itemnumber=[% hold.itemnumber | uri %]&reserve_id=[% hold.reserve_id | uri %]&date=[% hold.date | uri %]'" type="button" value="[% IF hold.intransit %]Đảo ngược tình trang di chuyển[% ELSE %]Đảo ngược tình trạng chờ đợi[% END %]">
 [%- END -%]
 </td>
 [% IF ( hold.intransit || hold.atdestination ) %]
 <td><input class="printholdslip" data-reserve_id="[% hold.reserve_id | html %]" name="printholdslip" type="button" value="Thông tin ghi mượn"></td>
 [% ELSE %]
 <td></td>
 [% END %]
 </tr>
 [% END %]
</table>
